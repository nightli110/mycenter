#include "myserver.hpp"

using namespace std;

MyServer::MyServer(int port) {
    server = make_shared<webcc::Server>(boost::asio::ip::tcp::v4(), port);
}

int MyServer::AddRoute(string path, shared_ptr<webcc::View> view) {
    server->Route(path, view);
    // TODO  log
    return 1;
}

shared_ptr<webcc::Server> MyServer::GetServer() {
    return server;
}