#include <iostream>
#include <thread>

#include "Globaldef.hpp"
#include "webcc/logger.h"
#include "webcc/response_builder.h"
#include "webcc/server.h"


class RegisterView : public webcc::View
{
public:
    webcc::ResponsePtr Handle(webcc::RequestPtr request) override;

private:
    webcc::ResponsePtr Get(webcc::RequestPtr request);

    webcc::ResponsePtr Post(webcc::RequestPtr request);
};