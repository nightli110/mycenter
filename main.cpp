#include <iostream>
// #include "InferenceAPP.hpp"
#include "MyRegister.hpp"
#include "json/json.h"
using namespace std;


void runserver(InferenceAPPMap *myapp) {
    webcc::Server server{boost::asio::ip::tcp::v4(), 8080};

    auto view = std::make_shared<RegisterView>(myapp);
    server.Route("/", view);
    server.Route("/hello", view);
    server.Run(1);
}

int main()
{
    WEBCC_LOG_INIT("", webcc::LOG_CONSOLE);
    LOG_USER("Workers: %d", 1);
    LOG_USER("Sleep seconds: %d", 1);
    MyDB db;
    InferenceAPPMap mytest;
    MYSQL_RES *result;
    db.initDB("localhost", "root", "123456", "application");

    mytest.InitDB(&db);
    // mytest.GetInferenceDB()->fetch_result("SELECT * from app;");
    // mytest.MysqlResToAppMap(db.getmysqlresult());

    runserver(&mytest);
    // while (1) {
    //     cout << "1" << endl;
    //     sleep(1);
    // }
    cout << "1" << endl;
    return 0;
}