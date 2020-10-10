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

#include "MyRegister.hpp"
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
    shared_ptr<RegisterView> Registerapp = make_shared<RegisterView>(&mytest);
    server.resource["^/inference/register"]["POST"] = [Registerapp](shared_ptr<HttpServer::Response> response, shared_ptr<HttpServer::Request> request) {
        try
        {
            string request_str = request->content.string();

            string response_str = Registerapp->Post(request_str);

            response->write(request_str);
        }
        catch (const exception &e)
        {
            *response << "HTTP/1.1 400 Bad Request\r\nContent-Length: " << strlen(e.what()) << "\r\n\r\n"
                      << e.what();
        }
    };

    server.resource["^/inference/unregister"]["POST"] = [](shared_ptr<HttpServer::Response> response, shared_ptr<HttpServer::Request> request){

    }
    server.resource["^/inference/online"]["POST"] = [Registerapp](shared_ptr<HttpServer::Response> response, shared_ptr<HttpServer::Request> request) {
          
    };

    server.resource["^/inference/offline"]["POST"] = [](shared_ptr<HttpServer::Response> response, shared_ptr<HttpServer::Request> request){

    };

    server.resource[] server.resource["^/info$"]["GET"] = [](shared_ptr<HttpServer::Response> response, shared_ptr<HttpServer::Request> request) {
        cout << "1111" << endl;
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