#ifndef GMLISTONLINEUSER_H
#define GMLISTONLINEUSER_H

#include <Network/OctetsStream.h>
#include <Utils.h>

class GMListOnlineUser : public OctetsStream
{
public:
    GMListOnlineUser() : OctetsStream() {}
    virtual ~GMListOnlineUser() {}

    static const uint opcode = 0x160;
    int gmroleid = 32;
    int localsid = 1;
    int handler  = -1;
    Octets cond  = Utils::emptyOctets();

    // OctetsStream interface
public:
    void Unmarshal() override;
    void Marshal() override;
};

#endif // GMLISTONLINEUSER_H
