#ifndef SYSSENDMAIL_H
#define SYSSENDMAIL_H

#include <Network/OctetsStream.h>

#include <Models/GRoleInventory.h>

class SysSendMail : public OctetsStream
{
public:
    SysSendMail() : OctetsStream() {}
    virtual ~SysSendMail() {}

    static const uint opcode = 0x1076;

    int tid = 334;
    int sysid = 1025;
    char sys_type = 3;
    int receiver;
    Octets title;
    Octets context;
    GRoleInventory attach_obj;
    int attach_money = 0;

public:
    void Unmarshal() override;
    void Marshal() override;

};

#endif // SYSSENDMAIL_H
