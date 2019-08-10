#ifndef GMLISTONLINEUSERRES_H
#define GMLISTONLINEUSERRES_H

#include <Network/OctetsStream.h>
#include <Utils.h>

#include <Models/GMPlayerInfo.h>

class GMListOnlineUserRes : public OctetsStream
{
public:
    GMListOnlineUserRes() : OctetsStream() {}
    virtual ~GMListOnlineUserRes() {}

    int	retcode;
    int	gmroleid;
    int	localsid;
    int	handler;
    uint userlist_size;
    QVector<GMPlayerInfo> userlist;

public:
    void Unmarshal() override;
    void Marshal() override;
};

#endif // GMLISTONLINEUSERRES_H
