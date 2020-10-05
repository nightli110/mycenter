
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
    if(JsonStringToinferenceAPP(request->data(), &myapp))

}

webcc::ResponsePtr RegisterView::Get(webcc::RequestPtr request)
{

}
