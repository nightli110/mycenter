#include <iostream>
#include "InferenceAPP.hpp"
#include "json/json.h"
using namespace std;

int main()
{
    MyDB db;
    InferenceAPPMap mytest;
    MYSQL_RES *result;
    db.initDB("localhost", "root", "123456", "application");

    db.fetch_result("SELECT * from app;");
    mytest.MysqlResToAppMap(db.getmysqlresult());

    cout << "1" << endl;
    return 0;
}