
#include <iostream>

#include "webcc/logger.h"
#include "webcc/response_builder.h"
#include "webcc/server.h"

using namespace std;

class MyServer : public webcc::View {
   private:
    shared_ptr<webcc::Server> server;

   public:
    MyServer(int port);
    int AddRoute(string path, shared_ptr<webcc::View> view);

    shared_ptr<webcc::Server> GetServer();
};

class HelloView : public webcc::View {
   public:
    HelloView(int sleep_seconds) : sleep_seconds_(sleep_seconds) {}

    webcc::ResponsePtr Handle(webcc::RequestPtr request) override {
        if (sleep_seconds_ > 0) {
            std::this_thread::sleep_for(std::chrono::seconds(sleep_seconds_));
        }

        if (request->method() == "GET") {
            return webcc::ResponseBuilder{}.OK().Body("Hello, World!")();
        }

        return {};
    }

   private:
    int sleep_seconds_;
};
