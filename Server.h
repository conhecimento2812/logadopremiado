#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpSocket>

class Server : QObject
{
    Q_OBJECT
public:
    explicit Server(QObject  *parent = nullptr);

private:
    QTcpSocket *socket = nullptr;

};

#endif // SERVER_H
