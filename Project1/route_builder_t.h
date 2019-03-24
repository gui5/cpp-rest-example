#pragma once
#include "iroute.h"




// factory of routes
class route_builder_t {

    template <typename V>
    static utility::string_t to_str_impl(const V& data) {
        utility::ostringstream_t ss;
        ss << data;
        return ss.str();
    }

    template<typename ...Args>
    static utility::string_t build_path(Args const& ...args) {
        utility::ostringstream_t ss;
        ((ss << U("/") << to_str_impl(args)), ...);
        return ss.str();

    }

public:

    route_builder_t(void) = default;
    ~route_builder_t(void) = default;


    //port, address (eg. localhost), paths (list, products, v2 )->list/products/v2
    template <typename T, typename ...Paths>
    static std::unique_ptr<T> make_route(std::wstring_view port
        , std::wstring_view host, Paths...paths) {

        web::uri_builder buri;
        buri.set_scheme(U("http"));
        buri.set_host(utility::string_t{ host });
        buri.set_port(utility::string_t{ port });
        buri.set_path(build_path(paths...));

        auto uri = buri.to_uri();

        return std::make_unique<T>(uri);
    }



};