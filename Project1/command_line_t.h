#pragma once
#include "command_line_data_t.h"
#include "icommand_line_t.h"

class command_line_t :
    public icommand_line_t
{
    command_line_data_t& _data;

public:
    command_line_t(command_line_data_t & data):
        _data{data}{}

    ~command_line_t(void) = default;

    const utility::string_t& port(void)override {
        return _data.port;
    }
    const utility::string_t& host(void)override {
        return _data.host;
    }


};