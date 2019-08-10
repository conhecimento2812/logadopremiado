#ifndef PUBLICCHAT_H
#define PUBLICCHAT_H

#include <Network/Octets.h>
#include <Network/OctetsStream.h>
#include <Utils.h>

class PublicChat : public OctetsStream
{
public:
    PublicChat() : OctetsStream() {}
    virtual ~PublicChat() {}

    static const uint opcode = 0x4F;

    char channel = 9;
    char emotion = 0;
    int  roleid = 16;
    int  localsid = -1;
    Octets message = Octets(Utils::toUtf16LE("Empty message!"));
    Octets data = Octets();

public:
    void Unmarshal() override;
    void Marshal() override;
};

#endif // PUBLICCHAT_H
