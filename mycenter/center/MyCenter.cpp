#include <iostream>
#include "MyCenter.hpp"
using namespace std;

MyCenter::MyCenter()
{

}

bool MyCenter::ProcessData(Json::Value request_json)
{

    //TODO 定时器
    read_lock Rlock(read_write_mutex);
    string ReqAppName = request_json['appname'].asString();
    if (AppStatus.count(ReqAppName))
    {
        if(AppStatus[ReqAppName] == 2)
        {
               // bool  resstatus = PostData();
        }
        else if (AppStatus[ReqAppName]==3)
        {
                //bool restatus = CallInferenceOnline(ReqAppName);
        }
    }
    else
    {
        return false;
    }
    
}

//TODO
bool MyCenter::PostData(Json::Value request_json)
{
    return true;
}

 bool MyCenter::CallInferenceOnline(string Inferencename)
 {
     return true;
 }

void MyCenter::InitCenter(InferenceAPPMap* MyAppMap)
{
    CenterAppMap = MyAppMap;
    UpdateAppdata();
}

void MyCenter::UpdateAppdata()
{
    write_lock wlock(read_write_mutex);
    for(auto APP: CenterAppMap->GetInferenceMap())
    {
        AppStatus[APP.first] = APP.second.model_status;
    }
}