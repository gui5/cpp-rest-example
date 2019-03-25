#pragma once
#include<cpprest/containerstream.h>
struct icommand_line_t
{
    virtual const utility::string_t& port(void) = 0;
    virtual const utility::string_t& host(void) = 0;
};