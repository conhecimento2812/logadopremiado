#include "PublicChat.h"

void PublicChat::Unmarshal()
{

}

void PublicChat::Marshal()
{
    Reset();

    this->operator<<(channel);
    this->operator<<(emotion);
    this->operator<<(roleid);
    this->operator<<(localsid);
    this->operator<<(message);
    this->operator<<(data);
}
