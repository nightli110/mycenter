#include <iostream>
#include "MyCenter.hpp"
using namespace std;

bool MyCenter::ProcessData(Json::Value request_json)
{

    //TODO 定时器
    read_lock Rlock(read_write_mutex);
    string ReqAppName = request_json['appname'].asString();
    if (AppStatus.count(ReqAppName))
    {
        if(AppStatus[ReqAppName] == 1&& AppStatus[ReqAppName] ==3)
        {
                bool  resstatsu = PostData();
        }
    }
    else
    {
        return false;
    }
    
}

//TODO
bool MyCenter::PostData()
{

}

 bool MyCenter::CallInferenceOnline(string Inferencename)
 {

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