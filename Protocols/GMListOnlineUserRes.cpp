#include "GMListOnlineUserRes.h"

void GMListOnlineUserRes::Unmarshal()
{
    this->operator>>(retcode);
    this->operator>>(gmroleid);
    this->operator>>(localsid);
    this->operator>>(handler);

    userlist_size = this->uncompact_uint32();

    for (uint i = 0; i < userlist_size; i++) {
        GMPlayerInfo player;
        this->operator>>(player.userid);
        this->operator>>(player.roleid);
        this->operator>>(player.linkid);
        this->operator>>(player.localsid);
        this->operator>>(player.gsid);
        this->operator>>(player.status);
        this->operator>>(player.name);
        userlist.push_back(player);
    }
}

void GMListOnlineUserRes::Marshal()
{
}
