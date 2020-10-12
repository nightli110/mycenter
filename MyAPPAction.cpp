/***
 * @Author: nightli
 * @Date: 2020-09-29 16:18:10
 * @LastEditors: nightli
 * @LastEditTime: 2020-10-12 17:08:38
 * @FilePath: /mycenter/MyAPPAction.cpp
 * @Emile: 1658484908@qq.com
 */
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
        auto suc = appmap->InferenceMapRemove(myapp);

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

string MyAPPActionView::AppOnline(string requestjson)
{
    inferenceAPP myapp;
    cout << "online" << endl;
    if (JsonStringToinferenceAPP(requestjson, &myapp))
    {
        Json::Value json;
        auto suc = appmap->InferenceMapUpdate(myapp);

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
    cout << "offline" << endl;
    if (JsonStringToinferenceAPP(requestjson, &myapp))
    {
        Json::Value json;
        auto suc = appmap->InferenceMapUpdate(myapp);

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

string MyAPPActionView::GetMap()
{
    auto appinfor = appmap->GetInferenceMap();
    string response_str = "";
    for (auto iter = appinfor.begin(); iter != appinfor.end(); iter++)
    {
        string name = iter->first;
        string info = inferenceAPPToJsonString(iter->second);
        response_str = response_str + name + ": " + info + "; ";
    }

    cout << "GetMap" << endl;
    return response_str;
}
