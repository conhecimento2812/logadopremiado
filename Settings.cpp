#include "Settings.h"
#include <QDebug>

QString Settings::path = "";
QString Settings::Z_pF22bgVxJ = "";
QString Settings::path_items_list = "";

bool Settings::announce = true;
int Settings::minutes = 60;
QList<int> Settings::gms = {};

QString Settings::mysql_host = "";
int Settings::mysql_port = 0;
QString Settings::mysql_user = "";
QString Settings::mysql_pass = "";
QString Settings::mysql_db = "";

QString Settings::gdeliveryd_host = "127.0.0.1";
quint16 Settings::gdeliveryd_port = 29100;

void Settings::Init(const QString &file)
{
    QSettings settings(file + "/logadopremiado.conf", QSettings::IniFormat);

    path    = file;
    path_items_list = path + "/items.list";
    Z_pF22bgVxJ = settings.value("logadopremiado/license").toString();

    announce = settings.value("logadopremiado/announce").toBool();
    minutes = settings.value("logadopremiado/minutes").toInt();

    auto stringListGms = settings.value("logadopremiado/gms").toStringList();
    for(int i = 0; i < stringListGms.length(); i++) {
        gms.push_back(stringListGms[i].toInt());
    }

    mysql_host = settings.value("mysql/host").toString();
    mysql_port = settings.value("mysql/port").toInt();
    mysql_user = settings.value("mysql/user").toString();
    mysql_pass = settings.value("mysql/pass").toString();
    mysql_db   = settings.value("mysql/db").toString();

    gdeliveryd_host = settings.value("gdeliveryd/host").toString();
    gdeliveryd_port = static_cast<quint16>(settings.value("gdeliveryd/port").toInt());
}
