#pragma once
#include "iroute.h"
#include "route_builder_t.h"

#include <list>
#include <string_view>

class router_manager_t {

    std::list<std::unique_ptr<iroute_t>> _routes;

public:
    router_manager_t(void) = default;
    ~router_manager_t(void) = default;

    void start(void) {
        for (auto& route : _routes) {
            route->listen();
        }
    }

    void terminate(void) {
        for (auto& route : _routes) {
            route->stop();
        }
    }
    /*
     port, address (eg. localhost), paths (list, products, v2 )->list/products/v2
    */
   
    template <typename T, typename ...Paths>
    void add(std::wstring_view port
        , std::wstring_view host, Paths...paths) {
        _routes.emplace_back(route_builder_t::make_route<T>(port, host, paths...));
    }

};