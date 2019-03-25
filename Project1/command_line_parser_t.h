#pragma once
#include <cpprest/containerstream.h>

#include "command_line_data_t.h"
#include "command_line_t.h"

class command_line_parser_t {
    command_line_data_t& _data;
public:
    command_line_parser_t(command_line_data_t& data) :
        _data{ data } {}

    command_line_t parse(int argc, char** argv);
};