#include "InferenceAPP.hpp"
using namespace std;

Json::Value inferenceAPPToJson(const inferenceAPP myapp)
{
    Json::Value myjson;
    myjson["id"] = myapp.id;
    myjson["inference_name"] = myapp.inference_name;
    myjson["model_name"] = myapp.model_name;
    myjson["register_name"] = myapp.register_time;
    myjson["ip"] = myapp.ip;
    myjson["status"] = myapp.status;
    myjson["inference_input"] = myapp.inference_input;
    myjson["inference_output"] = myapp.inference_output;
    myjson["model_status"] = myapp.model_status;
    myjson["model_memery"] = myapp.model_memery;

    return myjson;
}

inferenceAPP JsonToinferenceAPP(const Json::Value myjson)
{
    inferenceAPP myapp;
    myapp.id = myjson["id"].asString();
    myapp.inference_name = myjson["inference_name"].asString();
    myapp.model_name = myjson["model_name"].asString();
    myapp.register_time = myjson["register_time"].asString();
    myapp.ip = myjson["ip"].asString();
    myapp.status = 0;
    myapp.inference_input = myjson["inference_input"].asString();
    myapp.inference_output = myjson["inference_output"].asString();
    myapp.model_status = myjson["model_status"].asInt();
    myapp.model_memery = myjson["model_memery"].asDouble();

    return myapp;
}

string inferenceAPPToJsonString(const inferenceAPP &myapp)
{

    return JsonToString(inferenceAPPToJson(myapp));
}

bool JsonStringToinferenceAPP(const string &json_str, inferenceAPP *myapp)
{
    Json::Value json = StringToJson(json_str);

    if (!json)
    {
        return false;
    }

    *myapp = JsonToinferenceAPP(json);
    return true;
}

void InferenceAPPMap::InitDB(MyDB *mydb)
{
    registerdb = mydb;
}

bool InferenceAPPMap::MysqlResToAppMap(MYSQL_RES *result)
{
    if (result)
    {
        write_lock wlock(read_write_mutex);
        int num_fields = mysql_num_fields(result);
        int num_rows = mysql_num_rows(result);
        MYSQL_ROW row;

        for (int i = 0; i < num_rows; i++)
        {
            row = mysql_fetch_row(result);
            for (int j = 0; j < num_fields; j++) //输出每一字段
            {
                cout << row[j] << "\t\t";
            }
            if (row < 0)
            {
                cout << "no register inference app" << endl;
                break;
            }

            string name = MysqlRowToName(row);

            auto inferenceapp = MysqlRowToApp(row);
            AppMap[name] = inferenceapp;
        }
        return true;
    }
    else
    {
        cout << "MYSQL_RES is NULL" << endl;
        return true;
    }
}

inferenceAPP InferenceAPPMap::MysqlRowToApp(MYSQL_ROW row)
{
    inferenceAPP myapp;

    myapp.id = row[0];
    myapp.inference_name = row[1];
    myapp.model_name = row[2];
    myapp.register_time = row[3];
    myapp.ip = row[4];
    myapp.status = atoi(row[5]);
    myapp.inference_input = row[6];
    myapp.inference_output = row[7];
    myapp.model_status = atoi(row[8]);
    myapp.model_memery = atof(row[9]);
    return myapp;
}

string InferenceAPPMap::MysqlRowToName(MYSQL_ROW row)
{
    string str(row[1]);

    return str;
}

bool InferenceAPPMap::InferenceMapAdd(inferenceAPP myapp)
{
    write_lock wlock(read_write_mutex);
    if (AppMap.count(myapp.inference_name))
    {
        cout << "app has registerd" << endl;
        return false;
    }
    else
    {
        //TODO 写log 异常  异步写入数据库
        AppMap[myapp.inference_name] = myapp;
        InferenceMapToDB(myapp);
        cout << "app add success" << endl;
    }
    return true;
}

bool InferenceAPPMap::InferenceMapRemove(inferenceApp myapp)
{
    write_lock wlock(read_write_mutex);
    if (AppMap.count(myapp.inference_name))
    {
        AppMap.erase(myapp.inference_name);
        return true;
    }
    else
    {
        count << "app not register" << endl;
        return false;
    }
}

bool InferenceAPPMap::InferenceMapToDB(inferenceAPP myapp)
{
    string sqlstr;
    if (myapp.status == 0)
    {
        sqlstr = "insert into app(inference_name, model_name, register_time, "
                 "ip, status, inference_input, inference_output, model_status, model_memery) values(\"" +
                 myapp.inference_name + "\", \"" + myapp.model_name + "\", \"" + myapp.register_time + "\",\"" + myapp.ip +
                 "\", \"" + to_string(myapp.status) + "\", \"" + myapp.inference_input + "\", \"" + myapp.inference_output + "\", \"" +
                 to_string(myapp.model_status) + "\", \"" + to_string(myapp.model_memery) + "\")";
        cout << sqlstr << endl;
    } else if (myapp.status == 1)
    {
        sqlstr = "delete from app where inference_name =  \"" + myapp.inference_name  +"\")";
        cout<<sqlstr<<endl;
    }

    bool DBsuccess = registerdb->exeSQL(sqlstr);

    return DBsuccess;
}

MyDB *InferenceAPPMap::GetInferenceDB()
{
    return registerdb;
}