#ifndef QUEST_H
#define QUEST_H

#include <QString>
#include <Network/Octets.h>

struct GRoleInventory
{
    GRoleInventory(QString name = "null", int id = 0, int count = 0, Octets octets = Octets(), int proctype = 0, int guid1 = 0, int guid2 = 0, int mask = 0)
        : name(name), id(id), count(count), max_count(count), data(octets), proctype(proctype), guid1(guid1), guid2(guid2), mask(mask) {}

    QString name;
    int id;
    int pos = 0;
    int count;
    int max_count;
    Octets data;
    int proctype;
    int expire_date = 0;
    int guid1;
    int guid2;
    int mask;
};

#endif // QUEST_H
