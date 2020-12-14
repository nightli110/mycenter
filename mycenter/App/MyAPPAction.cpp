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

//TODO 返回值换成returnmessage 带错误信息 解除注册消息格式验证
string MyAPPActionView::AppUnRegister(string requestjson)
{
    inferenceAPP myapp;
    LOG(INFO) << "unregister";
    if (JsonStringToinferenceAPP(requestjson, &myapp))
    {
        Json::Value json;

        if(myapp.status!=1){
            json["success"] = false;
            json["failedmessage"] = "app unregister post message status error";
            auto reponsejson =JsonToString(json);
            return reponsejson;
        }
        
        auto suc = appmap->InferenceMapRemove(myapp);

        json["success"] = suc;
        auto reponsejson = JsonToString(json);
        return reponsejson;
    }
    else
    {
        Json::Value json;
        json["success"] = "failed";
        json["failedmessage"] = "JsonstringtoinferenceAPP failed ";
        auto reponsejson = JsonToString(json);
        return reponsejson;
    }
}

string MyAPPActionView::AppOnline(string requestjson)
{
    inferenceAPP myapp;
    LOG(INFO)<<"App online";
    if (JsonStringToinferenceAPP(requestjson, &myapp))
    {
        Json::Value json;

        if(myapp.status!=2){
            json["success"] = false;
            json["failedmessage"] = "app online post message status error";
            auto reponsejson =JsonToString(json);
            return reponsejson;
        }

        auto suc = appmap->InferenceMapUpdate(myapp);

        json["success"] = suc;
        auto reponsejson = JsonToString(json);
        return reponsejson;
    }
    else
    {
        Json::Value json;
        json["success"] = "failed";
        json["failedmessage"] = "JsonstringtoinferenceAPP failed ";
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
        
        if(myapp.status!=3){
            json["success"] = false;
            json["failedmessage"] = "app offline post message status error";
            auto reponsejson =JsonToString(json);
            return reponsejson;
        }

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
