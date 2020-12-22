#pragma once

#include <iostream>
#include <string>
#include <deque>
#include <glog/logging.h>

#include "../datatype/MyData.hpp"
#include "../common/Common.hpp"

using namespace std;

class messagequeue{
public:
    deque<DataInfo*> datawaitqueue;

    //TODO:对于处理失败情况    
    // deque<DataInfo*> datasendqueue;

    messagequeue(int max);
    bool waitpush(DataInfo *data);

    void waitpop();

    void waititemdelete();
    
    bool waitempty()

    //void finditem(string name)
    // void sendpush(DataInfo *data);

    // void waitpop();

    // void waititemdelete();
    
    // bool waitempty()

private:
    boost::shared_mutex mtx;

    int messagequeuelen;

    int maxlen;

}