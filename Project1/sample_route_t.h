#pragma once
#include "iroute.h"
class sample_route_t :
    public iroute_t
{
   
public:
    void on_get(web::http::http_request req)override;

    sample_route_t(web::uri uri);
    ~sample_route_t(void) = default;
};

