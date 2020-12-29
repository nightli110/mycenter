#include <iostream>
#include <string>
#include <thread>


#include "threadpool/ThreadPool.h"
#include "Json/Json.hpp"
#include "../messagequeue/messagequeue.hpp"
#include "../datatype/MyData.hpp"
using namespace std;
class sendprc
{
public:
    thread* recvthread;

    ThreadPool pool;
    messagequeue mslist;

    sendprc(int maxlen);

    void addsendtask(DataInfo &data);

    void postdata();
}