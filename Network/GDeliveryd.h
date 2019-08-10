#ifndef GDELIVERYD_H
#define GDELIVERYD_H

#include <QObject>
#include <QTcpSocket>
#include <Utils.h>
#include <Settings.h>

#include <Network/OctetsStream.h>

#include <Protocols/GMListOnlineUser.h>
#include <Protocols/GMListOnlineUserRes.h>
#include <Protocols/SysSendMail.h>
#include <Protocols/PublicChat.h>

#include <Models/GMPlayerInfo.h>
#include <Models/GRoleInventory.h>

class GDeliveryd : public QObject
{
    Q_OBJECT
public:
    explicit GDeliveryd(QObject *parent = nullptr) : QObject(parent) {
        host = Settings::gdeliveryd_host;
        port = Settings::gdeliveryd_port;
    }
    ~GDeliveryd() { socket->close(); }
    static GDeliveryd *Instance();

    void connect();
    QByteArray response();
    QVector<GMPlayerInfo> getUsersOnline();
    void sendMail(int roleid, GRoleInventory item, Octets title, Octets context);
    void publicChat(char channel, QString message);

private:
    static GDeliveryd *self;
    QTcpSocket *socket;
    QString host;
    quint16 port;
};

#endif // GDELIVERYD_H
