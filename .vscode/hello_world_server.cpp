#include <iostream>
#include <thread>

#include "webcc/logger.h"
#include "webcc/response_builder.h"
#include "webcc/server.h"

using namespace std;

void runserver() {
    webcc::Server server{boost::asio::ip::tcp::v4(), 8080};

    auto view = std::make_shared<HelloView>(1);
    server.Route("/", view);
    server.Route("/hello", view);

    server.Run(1);
}

int main(int argc, const char* argv[]) {
    WEBCC_LOG_INIT("", webcc::LOG_CONSOLE);

    int workers = 1;
    int sleep_seconds = 0;

    if (argc > 1) {
        workers = std::stoi(argv[1]);
        if (argc > 2) {
            sleep_seconds = std::stoi(argv[2]);
        }
    }

    LOG_USER("Workers: %d", workers);
    LOG_USER("Sleep seconds: %d", sleep_seconds);

    thread t{runserver};
    t.detach();
    while (1) {
        cout << "1" << endl;
        sleep(1);
    }

    // try {
    //     webcc::Server server{boost::asio::ip::tcp::v4(), 8080};

    //     auto view = std::make_shared<HelloView>(sleep_seconds);
    //     server.Route("/", view);
    //     server.Route("/hello", view);

    //     server.Run(workers);

    // } catch (const std::exception&) {
    //     return 1;
    // }

    return 0;
}
