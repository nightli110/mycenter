#include "client_http.hpp"
#include "server_http.hpp"
#include <future>

#define BOOST_SPIRIT_THREADSAFE
#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ptree.hpp>

#include <algorithm>
#include <boost/filesystem.hpp>
#include <fstream>
#include <vector>
#ifdef HAVE_OPENSSL
#include "crypto.hpp"
#endif
#include <curl/curl.h>
#include "mycenter/App/MyAPPAction.hpp"
#include "mycenter/center/BaseCenter.hpp"
#include "mycenter/common/Common.hpp"
using namespace std;

using namespace boost::property_tree;

using HttpServer = SimpleWeb::Server<SimpleWeb::HTTP>;
using HttpClient = SimpleWeb::Client<SimpleWeb::HTTP>;

int main(int argc, char* argv[])
{

    FLAGS_logtostderr = 1;  //输出到控制台
    google::InitGoogleLogging(argv[0]);    // 初始化
    
    
    PrintMonster();
    HttpServer server;
    server.config.port = 5000;

    MyDB db;
    InferenceAPPMap mytest;
    MYSQL_RES *result;
    db.initDB("localhost", "root", "123456", "app");

    mytest.InitDB(&db);

    // MyCenter *CeneterView;
    shared_ptr<MyAPPActionView> AppActionView = make_shared<MyAPPActionView>(&mytest);
    AppActionView->GetAllApp();
    server.resource["^/helloworld"]["GET"]=[](shared_ptr<HttpServer::Response> response, shared_ptr<HttpServer::Request> request){

        try
        {
            LOG(INFO)<<"server helloworld";
            string response_str="helloworld";
            response->write(response_str);
        }
        catch (const exception &e)
        {
            LOG(ERROR)<<"helloworld return message:"<<e.what();
            *response << "HTTP/1.1 400 Bad Request\r\nContent-Length: " << strlen(e.what()) << "\r\n\r\n"
                      << e.what();
        }
    };

    server.resource["^/inference/register"]["POST"] = [AppActionView](shared_ptr<HttpServer::Response> response, shared_ptr<HttpServer::Request> request) {
        try
        {
            LOG(INFO)<<"server register";
            string request_str = request->content.string();

            string response_str = AppActionView->AppRegister(request_str);

            response->write(response_str);
        }
        catch (const exception &e)
        {
            LOG(ERROR)<<"register return message:"<<e.what();
            *response << "HTTP/1.1 400 Bad Request\r\nContent-Length: " << strlen(e.what()) << "\r\n\r\n"
                      << e.what();
        }
    };

    server.resource["^/inference/unregister"]["POST"] = [AppActionView](shared_ptr<HttpServer::Response> response, shared_ptr<HttpServer::Request> request) {
        try
        {
            LOG(INFO)<<"server unregister";
            string request_str = request->content.string();
            string response_str = AppActionView->AppUnRegister(request_str);
            response->write(response_str);
        }
        catch (const std::exception &e)
        {
            LOG(ERROR)<<"unregister return message:"<<e.what();
            *response << "HTTP/1.1 400 Bad Request\r\nContent-Length: " << strlen(e.what()) << "\r\n\r\n"
                      << e.what();
        }
    };

    server.resource["^/inference/online"]["POST"] = [AppActionView](shared_ptr<HttpServer::Response> response, shared_ptr<HttpServer::Request> request) {
        try
        {
            LOG(INFO)<<"server online";
            string request_str = request->content.string();
            string response_str = AppActionView->AppOnline(request_str);
            response->write(response_str);
        }
        catch (const std::exception &e)
        {
            LOG(ERROR)<<"online return message:"<<e.what();
            *response << "HTTP/1.1 400 Bad Request\r\nContent-Length: " << strlen(e.what()) << "\r\n\r\n"
                      << e.what();
        }
    };

    server.resource["^/inference/offline"]["POST"] = [AppActionView](shared_ptr<HttpServer::Response> response, shared_ptr<HttpServer::Request> request) {
        try
        {
            LOG(INFO)<<"server offline";
            string request_str = request->content.string();
            string response_str = AppActionView->AppOffLine(request_str);
            response->write(response_str);
        }
        catch (const std::exception &e)
        {
            LOG(ERROR)<<"offline return message:"<<e.what();
            *response << "HTTP/1.1 400 Bad Request\r\nContent-Length: " << strlen(e.what()) << "\r\n\r\n"
                      << e.what();
        }
    };

    server.resource["^/infomap"]["GET"] = [AppActionView](shared_ptr<HttpServer::Response> response, shared_ptr<HttpServer::Request> request) {
        try
        {
            LOG(INFO)<<"server get infomap";
            string response_str = AppActionView->GetMap();
            response->write(response_str);
        }
        catch (const std::exception &e)
        {
            LOG(ERROR)<<"infomap return message:"<<e.what();
            std::cerr << e.what() << '\n';
        }

        response->write(request->path_match[1].str());
    };

    // server.resource["^/dataabsorb"] = [](shared_ptr<HttpServer::Response>, shared_ptr<HttpServer::Request> request)
    // {

    // }


    // server.resource["^/omsdata"]["POST"] = [&CeneterView](shared_ptr<HttpServer::Response>, shared_ptr<HttpServer::Request> request)
    // {
    //     try
    //     {
    //         string request_str = request->content.string();
    //         Json::Value request_json = StringToJson(request_str);
                                                                                                                                     

    //     }
    //     catch(const std::exception& e)
    //     {
    //         std::cerr << e.what() << '\n';
    //     }
        
    // };

    promise<unsigned short> server_port;
    thread server_thread([&server, &server_port]() {
        // Start server
        LOG(INFO) << "server start";
        server.start([&server_port](unsigned short port) {
            server_port.set_value(port);
        });
    });
    server_thread.join();
    // return 1;
}