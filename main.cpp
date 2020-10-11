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

#include "MyAPPAction.hpp"
using namespace std;
// Added for the json-example:
using namespace boost::property_tree;

using HttpServer = SimpleWeb::Server<SimpleWeb::HTTP>;
using HttpClient = SimpleWeb::Client<SimpleWeb::HTTP>;

int main()
{
    HttpServer server;
    server.config.port = 8080;

    MyDB db;
    InferenceAPPMap mytest;
    MYSQL_RES *result;
    db.initDB("localhost", "root", "123456", "application");

    mytest.InitDB(&db);
    shared_ptr<MyAPPActionView> AppActionView = make_shared<MyAPPActionView>(&mytest);
    server.resource["^/inference/register"]["POST"] = [AppActionView](shared_ptr<HttpServer::Response> response, shared_ptr<HttpServer::Request> request) {
        try
        {
            string request_str = request->content.string();

            string response_str = AppActionView->AppRegister(request_str);

            response->write(response_str);
        }
        catch (const exception &e)
        {
            *response << "HTTP/1.1 400 Bad Request\r\nContent-Length: " << strlen(e.what()) << "\r\n\r\n"
                      << e.what();
        }
    };

    server.resource["^/inference/unregister"]["POST"] = [AppActionView](shared_ptr<HttpServer::Response> response, shared_ptr<HttpServer::Request> request) {
        try
        {
            /* code */
            string request_str = request->content.string();
            string response_str = AppActionView->AppUnRegister(request_str);
            response->write(response_str);
        }
        catch (const std::exception &e)
        {
            *response << "HTTP/1.1 400 Bad Request\r\nContent-Length: " << strlen(e.what()) << "\r\n\r\n"
                      << e.what();
        }
    } ;

    server.resource["^/inference/online"]["POST"] = [AppActionView](shared_ptr<HttpServer::Response> response, shared_ptr<HttpServer::Request> request) {
        try
        {
            /* code */
            string request_str = request->content.string();
            string response_str = AppActionView->AppOnline(request_str);
            response->write(response_str);
        }
        catch (const std::exception &e)
        {
            *response << "HTTP/1.1 400 Bad Request\r\nContent-Length: " << strlen(e.what()) << "\r\n\r\n"
                      << e.what();
        }
    };

    server.resource["^/inference/offline"]["POST"] = [AppActionView](shared_ptr<HttpServer::Response> response, shared_ptr<HttpServer::Request> request) {
        try
        {
            /* code */
            string request_str = request->content.string();
            string response_str = AppActionView->AppOffLine(request_str);
            response->write(response_str);
        }
        catch (const std::exception &e)
        {
            *response << "HTTP/1.1 400 Bad Request\r\nContent-Length: " << strlen(e.what()) << "\r\n\r\n"
                      << e.what();
        }
    };

    server.resource["^/infomap"]["GET"] = [AppActionView](shared_ptr<HttpServer::Response> response, shared_ptr<HttpServer::Request> request) {
        try
        {
                string response_str = AppActionView->GetMap();
                response->write(response_str);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
        response->write(request->path_match[1].str());
    };

    promise<unsigned short> server_port;
    thread server_thread([&server, &server_port]() {
        // Start server
        server.start([&server_port](unsigned short port) {
            server_port.set_value(port);
        });
    });
    server_thread.join();
}