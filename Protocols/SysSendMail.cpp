#include "SysSendMail.h"

void SysSendMail::Unmarshal()
{

}

void SysSendMail::Marshal()
{
    Reset();
    this->operator<<(tid);
    this->operator<<(sysid);
    this->operator<<(sys_type);
    this->operator<<(receiver);
    this->operator<<(title);
    this->operator<<(context);
        // object
        this->operator<<(attach_obj.id);
        this->operator<<(attach_obj.pos);
        this->operator<<(attach_obj.count);
        this->operator<<(attach_obj.max_count);
        this->operator<<(attach_obj.data);
        this->operator<<(attach_obj.proctype);
        this->operator<<(attach_obj.expire_date);
        this->operator<<(attach_obj.guid1);
        this->operator<<(attach_obj.guid2);
        this->operator<<(attach_obj.mask);
    this->operator<<(attach_money);
}
