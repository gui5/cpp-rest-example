#include <iostream>
#include "route_manager_t.h"
#include "sample_route_t.h"
#include "command_line_parser_t.h"


void print_routes(router_manager_t& rman) {
    for (auto& route : rman) {
        ucout << U("Listening at: ") << route->uri() << std::endl;
    }
}

int main(int argc, char** argv) {

    
    auto cmdline = command_line_parser_t::parse(argc, argv);


    router_manager_t rman;

    try {

        rman.add<sample_route_t>(cmdline.port(), cmdline.host(), U("hello"));

        rman.start();

        print_routes(rman);
        (void)getchar();

        rman.terminate();
    }
    catch (const std::exception & e)
    {
        std::cout <<"Exception: " << e.what() << std::endl;
    }


    return 0;
}