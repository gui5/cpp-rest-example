#pragma once
#include <cpprest/containerstream.h>

#include "command_line_data_t.h"
#include "command_line_t.h"

class command_line_parser_t {
    
public:
    command_line_parser_t(void) = default;
    ~command_line_parser_t(void) = default;

    static command_line_t parse(int argc, char** argv);
};