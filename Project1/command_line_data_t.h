#pragma once
#include <cpprest/containerstream.h>

class command_line_parser_t;
class command_line_t;

class command_line_data_t {

    command_line_data_t(void) = default;
    ~command_line_data_t(void) = default;

    utility::string_t port;
    utility::string_t host;

    friend class command_line_parser_t;
    friend class command_line_t;

public:

    static command_line_data_t& get(void) {
        static command_line_data_t data;
        return data;
    }
};