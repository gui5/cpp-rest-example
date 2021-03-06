#pragma once

/*
    base route class
*/

//cpprest sdk necessary includes
#include <cpprest/json.h>
#include <cpprest/http_listener.h>
#include <cpprest/uri.h>
#include <cpprest/asyncrt_utils.h>
#include <cpprest/json.h>
#include <cpprest/filestream.h>
#include <cpprest/containerstream.h>
#include <cpprest/producerconsumerstream.h>

   //You must inherit this class and implemet the rest methods


class iroute_t {

    web::http::experimental::listener::http_listener _listener;

    //change <Simple Rest Example> to your service name
   
    web::json::value responseNotImpl(const web::http::method& method) {
        auto response = web::json::value::object();
        response[U("serviceName")] = web::json::value::string(U("Simple Rest Example"));
        response[U("http_method")] = web::json::value::string(method);
        return response;
    }

    //you can bind rest methods here 
    void bind_methods(void) {
        _listener.support(web::http::methods::GET, std::bind(&iroute_t::on_get, this, std::placeholders::_1));
        _listener.support(web::http::methods::POST, std::bind(&iroute_t::on_post, this, std::placeholders::_1));
        _listener.support(web::http::methods::PUT, std::bind(&iroute_t::on_put, this, std::placeholders::_1));
        _listener.support(web::http::methods::PATCH, std::bind(&iroute_t::on_patch, this, std::placeholders::_1));
        _listener.support(web::http::methods::DEL, std::bind(&iroute_t::on_delete, this, std::placeholders::_1));
    }

public:

    /*feel free to add other rest methods here*/
    
    //handles http get
    virtual void on_get(web::http::http_request req) {
       req.reply(web::http::status_codes::NotImplemented,
          responseNotImpl(web::http::methods::GET)).wait();
    }

    //handles http post
    virtual void on_post(web::http::http_request req) {
        req.reply(web::http::status_codes::NotImplemented,
            responseNotImpl(web::http::methods::POST)).wait();
    }

    //handles http put
    virtual void on_put(web::http::http_request req) {
        req.reply(web::http::status_codes::NotImplemented,
            responseNotImpl(web::http::methods::PUT)).wait();
    }

    //handles gttp patch
    virtual void on_patch(web::http::http_request req) {
        req.reply(web::http::status_codes::NotImplemented,
            responseNotImpl(web::http::methods::PATCH)).wait();
    }

    //handles http delete
    virtual void on_delete(web::http::http_request req) {
        req.reply(web::http::status_codes::NotImplemented,
            responseNotImpl(web::http::methods::DEL)).wait();
    }

    //make the route active
    void listen(void) {
         _listener.open().wait();
    }

    //stops the route
    void stop(void) {
         _listener.close().wait();
    }

   
    //returns the route uri
    const utility::string_t uri(void) {
        return _listener.uri().to_string();
    }


    virtual ~iroute_t(void) = default;

    iroute_t(web::uri uri):_listener(uri) {
        bind_methods();
    }
};