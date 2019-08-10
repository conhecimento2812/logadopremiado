#include "GMListOnlineUser.h"

void GMListOnlineUser::Unmarshal()
{

}

void GMListOnlineUser::Marshal()
{
    Reset();
    this->operator<<(gmroleid);
    this->operator<<(localsid);
    this->operator<<(handler);
    this->operator<<(cond);
}
