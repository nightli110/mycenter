/*** 
 * @Author: nightli
 * @Date: 2020-10-13 17:15:52
 * @LastEditors: nightli
 * @LastEditTime: 2020-10-14 10:22:11
 * @FilePath: /mycenter/MyCenter.hpp
 * @Emile: 1658484908@qq.com
 */
#include <iostream>
#include "../App/InferenceAPP.hpp"
#include "../datatype/MyData.hpp"

using namespace std;

class MyCenter
{
public:

    MyCenter(const MyCenter&);
    bool ProcessData(Json::Value DataInfoJson);

    bool PostData();

    bool CallInferenceOnline(string Inferencename);

    void InitCenter(InferenceAPPMap* MyAppMap);

    void UpdateAppdata();

private:
    InferenceAPPMap *CenterAppMap;

    map<string, DataInfo> DataMsgs;
    map<string, bool> AppStatus;

    boost::shared_mutex read_write_mutex;
};