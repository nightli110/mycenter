
#include "MyRegister.hpp"

#include "webcc/response_builder.h"

webcc::ResponsePtr RegisterView::Handle(webcc::RequestPtr request)
{
    if (request->method() == "GET")
    {
        return Get(request);
    }
    if (request->method() == "POST")
    {
        return Post(request);
    }
    return {};
}

webcc::ResponsePtr RegisterView::Post(webcc::RequestPtr request)
{
    inferenceAPP myapp;
    if (JsonStringToinferenceAPP(request->data(), &myapp))
    {
        auto suc = appmap->InferenceMapAdd(myapp);

        Json::Value json;

        json["success"] = suc;
        return webcc::ResponseBuilder{}.Created().Body(JsonToString(json)).Json().Utf8()();
    }
    else
    {
        return webcc::ResponseBuilder{}.BadRequest()();
    }
}

webcc::ResponsePtr RegisterView::Get(webcc::RequestPtr request)
{
    //TODO
    return webcc::ResponseBuilder{}.BadRequest()();
}