#include "InferenceAPP.hpp"

using namespace std;

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
    cout<<str<<endl;
    return str;
}
