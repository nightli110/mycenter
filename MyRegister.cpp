
#include "MyRegister.hpp"

#include "webcc/response_builder.h"


RegisterView::RegisterView(InferenceAPPMap* mymap)
{
    appmap = mymap;
}

webcc::ResponsePtr RegisterView::Handle(webcc::RequestPtr request)
{
    if (request->method() == "GET")
    {
        return Get(request);
    }
    if (request->method() == "POST")
    {
        cout<<"hello"<<endl;
        return Post(request);
    }
    return {};
}

webcc::ResponsePtr RegisterView::Post(webcc::RequestPtr request)
{
    inferenceAPP myapp;
     cout<<"hello"<<endl;
    if (JsonStringToinferenceAPP(request->data(), &myapp))
    {
        auto suc = appmap->InferenceMapAdd(myapp);
        cout<<"hello"<<endl;
        Json::Value json;

        json["success"] = "hhhhhhhh";
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
    cout<<"hello world"<<endl;
    return webcc::ResponseBuilder{}.BadRequest()();
}

