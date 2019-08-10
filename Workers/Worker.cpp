#include "Worker.h"

Worker::Worker()
{
    mysql = new MySQL();
    mysql->connect();

    gdeliveryd = new GDeliveryd();
    gdeliveryd->connect();

    loadItems();

    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(lottery()));
    timer->start(Settings::minutes * 60 * 1000);
    //timer->start(5000);
    lottery();
}

void Worker::lottery()
{
    auto players = filter(gdeliveryd->getUsersOnline());

    if (players.length() > 0) {
        int winner = rand() % players.length();
        int award = rand() % items.length();

        gdeliveryd->sendMail(players[winner].roleid, items[award], Octets(Utils::toUtf16LE("Logado Premiado")), Octets(Utils::toUtf16LE("Parabéns, você foi sorteado, segue a premiação")));

        QString winnerName = QByteArray::fromStdString(players[winner].name.text.toStdString()).replace(QChar::Null, "");
        QString itemName = QByteArray::fromStdString(items[award].name.toStdString()).replace(QChar::Null, "");

        if(Settings::announce) {
            gdeliveryd->publicChat(9, QString("%1 ganhou %2 no logado premiado!").arg(winnerName).arg(itemName));
        }

        auto message = QString("Players online: %1 Winner: %2 Award: %3 (%4)").arg(players.length()).arg(winnerName).arg(itemName).arg(items[award].count);

        Utils::print(message);
    }
}

void Worker::loadItems()
{
    QFile itemslist(Settings::path_items_list);
    if(!itemslist.open(QIODevice::ReadOnly)) {
        Utils::print(QString("Cold not read file %1").arg(Settings::path_items_list));
        exit(EXIT_FAILURE);
    }

    while(!itemslist.atEnd()) {
        QString line = itemslist.readLine().trimmed();
        QRegExp regex("(\\d+),(\\d+),([a-zA-Z0-9]+),(\\d+),(\\d+),(\\d+),(\\d+),(.*)");

        if(line.indexOf(regex) > -1) {
            regex.indexIn(line, 0);

            GRoleInventory item(
                        regex.cap(8), // name
                        regex.cap(1).toInt(), // id
                        regex.cap(2).toInt(), // count
                        regex.cap(3) == "0" ? Octets() : Octets(regex.cap(3).toStdString().c_str()), // octets
                        regex.cap(4).toInt(), // proctype
                        regex.cap(5).toInt(), // guid1
                        regex.cap(6).toInt(), // guid2
                        regex.cap(7).toInt()  // mask
            );
            items.push_back(item);
        }
    }

    if(items.length() <= 0) {
        Utils::print(QString("No awards found in %1").arg(Settings::path_items_list));
        exit(EXIT_FAILURE);
    }

    Utils::print(QString("Loaded %1 items").arg(items.length()));
}

QVector<GMPlayerInfo> Worker::filter(QVector<GMPlayerInfo> players)
{
    for (int i = 0; i < players.length(); i++) {
        if (Settings::gms.contains(players[i].userid)) {
            players.removeAt(i);
        }
    }

    return players;
}
