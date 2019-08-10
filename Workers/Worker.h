#ifndef WORKER_H
#define WORKER_H

#include <QTimer>

#include <Settings.h>
#include <Utils.h>

#include <Network/Octets.h>
#include <Network/GDeliveryd.h>

#include <Database/MySQL.h>

#include <Models/GRoleInventory.h>

class Worker : public QObject
{
    Q_OBJECT
public:
    Worker();

private slots:
    void lottery();
    void loadItems();

private:
    QVector<GMPlayerInfo> filter(QVector<GMPlayerInfo> players);

    QList<GRoleInventory> items;

    GDeliveryd *gdeliveryd;
    MySQL *mysql;
};

#endif // WORKER_H
