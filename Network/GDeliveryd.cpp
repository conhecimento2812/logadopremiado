#include "GDeliveryd.h"

GDeliveryd *GDeliveryd::self = nullptr;

GDeliveryd *GDeliveryd::Instance()
{
    if(!self)
        self = new GDeliveryd();
    return self;
}

void GDeliveryd::connect()
{
    socket = new QTcpSocket();
    socket->connectToHost(host, port);
    if (!socket->waitForConnected(3000)) {
        Utils::print(QString("Failed connect gdeliveryd: %1:%2").arg(host).arg(port));
        exit(EXIT_FAILURE);
    }

    this->response();
}

QVector<GMPlayerInfo> GDeliveryd::getUsersOnline()
{
    GMListOnlineUser listonline;
    listonline.socket = socket;
    listonline.Marshal();
    listonline.Send(listonline.opcode);

    GMListOnlineUserRes res;
    res.setData(this->response());
    res.Unmarshal();

    return res.userlist;
}

void GDeliveryd::sendMail(int roleid, GRoleInventory item, Octets title = Octets(), Octets context = Octets())
{
    SysSendMail sendmail;

    sendmail.receiver = roleid;
    sendmail.attach_obj = item;
    sendmail.title = title;
    sendmail.context = context;

    sendmail.socket = socket;
    sendmail.Marshal();
    sendmail.Send(sendmail.opcode);

    this->response();
}

void GDeliveryd::publicChat(char channel, QString message)
{
    PublicChat chat;

    chat.channel = channel;
    chat.message = Octets(Utils::toUtf16LE(message.toStdString().c_str()));

    chat.socket = socket;
    chat.Marshal();
    chat.Send(chat.opcode);

    this->response();
}

QByteArray GDeliveryd::response()
{
    socket->waitForBytesWritten(1000);
    socket->waitForReadyRead(3000);

    return socket->readAll();
}
