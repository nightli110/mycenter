/*** 
 * @Author: nightli
 * @Date: 2020-09-29 15:44:29
 * @LastEditors: nightli
 * @LastEditTime: 2020-10-14 10:00:14
 * @FilePath: /mycenter/InferenceAPP.hpp
 * @Emile: 1658484908@qq.com
 */
#pragma once

#include <string>
#include <iostream>
#include <map>
#include <mysql/mysql.h>

#include "../common/Common.hpp"
#include "../DB/MyDB.hpp"

using namespace std;

struct inferenceAPP
{
    string id;               //id 自增
    string inference_name;   //应用名字，暂时唯一
    string model_name;       //模型名字
    string register_time;    //注册时间
    string ip;               //ip+port
    int status;              //状态，0注册成功，1解除注册 数据库中移除，2上线，3下线
    string inference_input;  //模型输入支持image，text，e.g. {image:1;text:1}
    string inference_output; //模型输出支持image，text，e.g. {image:1;text:1}
    int model_status;        //模型状态，0：V-RAM，1：RAM，2：ROM
    double model_memery;     //模型占有RAM资源
};

Json::Value inferenceAPPToJson(const inferenceAPP myapp);

inferenceAPP JsonToinferenceAPP(const Json::Value myjson);

string inferenceAPPToJsonString(const inferenceAPP &myapp);

bool JsonStringToinferenceAPP(const string &json_str, inferenceAPP *myapp);

class InferenceAPPMap
{
public:
    void InitDB(MyDB *mydb);

    bool MysqlResToAppMap(MYSQL_RES *result);

    inferenceAPP MysqlRowToApp(MYSQL_ROW row);

    string MysqlRowToName(MYSQL_ROW row);

    bool InferenceMapAdd(inferenceAPP myapp);

    bool InferenceMapRemove(inferenceAPP myapp);

    bool InferenceMapUpdate(inferenceAPP myapp);

    bool InferenceMapToDB(inferenceAPP myapp);

    const map<string, inferenceAPP> GetInferenceMap();

    void GetDBALLApp();

    MYSQL_RES* InferenceMapfromDB();

    MYSQL_RES* InferenceMapfromDB(string inferencename);

    MyDB *GetInferenceDB();

private:
    map<string, inferenceAPP> AppMap;

    boost::shared_mutex read_write_mutex;
    int Mapsize;
    MyDB *registerdb;
};