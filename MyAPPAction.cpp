
#include "MyAPPAction.hpp"

MyAPPActionView::MyAPPActionView(InferenceAPPMap *mymap)
{
    appmap = mymap;
}

string MyAPPActionView::AppRegister(string requestjson)
{
    inferenceAPP myapp;
    cout << "register" << endl;
    if (JsonStringToinferenceAPP(requestjson, &myapp))
    {
        Json::Value json;
        auto suc = appmap->InferenceMapAdd(myapp);
        
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

string MyAPPActionView::AppUnRegister(string requestjson)
{
    inferenceAPP myapp;
    cout << "unregister" << endl;
    if (JsonStringToinferenceAPP(requestjson, &myapp))
    {
        Json::Value json;
        auto suc = InferenceMapRemove(myapp);
        
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

string  MyAPPActionView::AppOnline(string requestjson)
{
    inferenceAPP myapp;
    cout<<"online"<<endl;
    if (JsonStringToinferenceAPP(requestjson, &myapp))
    {
        Json::Value json;
        auto suc = InferenceMapUpdate(myapp);
        
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

string MyAPPActionView::AppOffLine(string requestjson)
{
    inferenceAPP myapp;
    cout<<"offline"<<endl;
    if (JsonStringToinferenceAPP(requestjson, &myapp))
    {
        Json::Value json;
        auto suc = InferenceMapUpdate(myapp);
        
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
string MyAPPActionView::Get(string request)
{
    //TODO
    cout << "hello world" << endl;
    return string("TODO");
}
