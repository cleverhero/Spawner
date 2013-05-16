#ifndef _SPAWNER_RESTRICTIONS_H_
#define _SPAWNER_RESTRICTIONS_H_

#include <string>

enum restriction_kind_t
{
    restriction_user_time_limit         = 0x0,
    restriction_memory_limit            = 0x1,
    restriction_processor_time_limit    = 0x2,
    restriction_security_limit          = 0x3,
    restriction_write_limit             = 0x4,
    restriction_load_ratio              = 0x5,
    restriction_max                     = 0x6
};

typedef unsigned int restriction_t;


const restriction_t restriction_no_limit = 0xffffffff;
const restriction_t restriction_limited  = 0x00000001;
//TODO move source to platform independent .cpp
class restrictions_class
{
private:
    restriction_t restrictions[restriction_max];
public:
    restrictions_class();
    void set_restriction(const restriction_kind_t &kind, const restriction_t &value);
    void set_restriction(const std::string &kind, const restriction_t &value);
    restriction_t get_restriction(const restriction_kind_t &kind) const;
    static restriction_kind_t restriction_by_name(const std::string &name);
};



#endif//_SPAWNER_RESTRICTIONS_H_