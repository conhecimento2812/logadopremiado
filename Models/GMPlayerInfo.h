#ifndef GMPLAYERINFO_H
#define GMPLAYERINFO_H

#include <Network/Octets.h>

struct GMPlayerInfo
{
    int     userid;
    int     roleid;
    int     linkid;
    int     localsid;
    int     gsid;
    char	status;
    Octets	name;
};

#endif // GMPLAYERINFO_H
