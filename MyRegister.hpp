#include <iostream>
#include <thread>

#include "InferenceAPP.hpp"
#include "webcc/logger.h"
#include "webcc/response_builder.h"
#include "webcc/server.h"


class RegisterView : public webcc::View
{
public:
    //TODO webcc 改                                
    RegisterView(InferenceAPPMap* mymap);
    webcc::ResponsePtr Handle(webcc::RequestPtr request) override;

private:
    webcc::ResponsePtr Get(webcc::RequestPtr request);

    webcc::ResponsePtr Post(webcc::RequestPtr request);

    InferenceAPPMap* appmap;
};