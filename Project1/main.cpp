#include <iostream>
#include "route_manager_t.h"
#include "sample_route_t.h"

int wmain(int argc, wchar_t** argv) {

    router_manager_t rman;
 
    try { 

        rman.add<sample_route_t>(U("8051"), U("localhost"), U("hello"));

        rman.start();
        (void)getchar();
        rman.terminate();
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
  

    return 0;
}