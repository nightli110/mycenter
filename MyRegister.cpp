
#include "MyRegister.hpp"

#include "webcc/response_builder.h"


RegisterView::RegisterView(InferenceAPPMap* mymap)
{
    appmap = mymap;
}



string RegisterView::Post(string requestjson)
{
    inferenceAPP myapp;
     cout<<"hello"<<endl;
    if (JsonStringToinferenceAPP(requestjson, &myapp))
    {
        auto suc = appmap->InferenceMapAdd(myapp);
        Json::Value json;

        json["success"] = suc;
        auto reponsejson = JsonToString(json);
        return reponsejson;
    }
    else
    {
        Json::Value json;

        json["success"] = "failed";
        auto reponsejson = JsonToString(json);
        return reponsejson;
    }
}

string RegisterView::Get(string request)
{
    //TODO
    cout<<"hello world"<<endl;
    return string("TODO");
}

