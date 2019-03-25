#include "command_line_parser_t.h"
#include <cxxopts.hpp>


command_line_t command_line_parser_t::parse(int argc, char** argv)
{
    auto& _data = command_line_data_t::get();
    bool help = false;
    cxxopts::Options options(argv[0], " - example command line options");

    std::string port;
    std::string host;

    try
    {
        options.add_option("config", "p", "port", "port to bind the service",
            cxxopts::value<std::string>(port)->default_value("8051"), "a port value");
        
        options.add_option("config", "i", "host", "host ip",
            cxxopts::value<std::string>(host)->default_value("localhost"), "the host ip");

        options.add_option("config", "h", "help", "displays help",
            cxxopts::value<bool>(help)->default_value("false"), " displays help message");

        auto result = options.parse(argc, argv);
        if (help) {
            std::cout << options.help({ "","config" }) << std::endl;
            exit(0);
        }

        _data.port = utility::string_t{ port.begin(),port.end() };
        _data.host = utility::string_t{ host.begin(),host.end() };

    }
    catch (const std::exception &)
    {
        std::cout << options.help({ "","config" }) << std::endl;
        exit(0);
    }


    return command_line_t(_data);
}
