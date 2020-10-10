
#include "MyRegister.hpp"

#include "webcc/response_builder.h"


RegisterView::RegisterView(InferenceAPPMap* mymap)
{
    appmap = mymap;
}



string RegisterView::AppRegister(string requestjson)
{
    inferenceAPP myapp;
     cout<<"register"<<endl;
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

string RegisterView::AppUnRegister(string requestjson)
{
    inferenceAPP myapp;
    cout<<"unregister"<<endl;
    if (JsonStringToinferenceAPP(requestjson, &myapp))
    {
        
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

