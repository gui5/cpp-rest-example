#include "sample_route_t.h"



void sample_route_t::on_get(web::http::http_request req)
{
    ucout << req.to_string() << std::endl;
  
    web::json::value response;
    response[U("sucess")] = web::json::value::string(U("Hello World"));
    (void)req.reply(web::http::status_codes::OK, response);

}

void sample_route_t::on_post(web::http::http_request req)
{
}

void sample_route_t::on_put(web::http::http_request req)
{
}

void sample_route_t::on_patch(web::http::http_request req)
{
}

void sample_route_t::on_delete(web::http::http_request req)
{
}

sample_route_t::sample_route_t(web::uri uri) :
    iroute_t(uri)
{
    
}
