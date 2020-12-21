#include "messagequeue.hpp"

messagequeue::messagequeue(int maxmessagesnums)
{
    maxlen = maxmessagenums;
}


void messagequeue::pop()
{
    boost::shared_lock<boost::shared_mutex> lk(mtx);
    
}

bool messagequeue::push(DataInfo &dataitem)
{
    boost::unique_lock<boost::shared_mutex> lk(mtx);
    if(dataqueue.size()>maxlen)
    {
        LOG(WARNING)<<"over dataqueue max size";
        return false;
    } 

    dataqueue.push_back(dataitem);
    LOG(INFO)<<"add dataitem";
    return true

}

void messagequeue::itemdelete(iterator ite)
{
    
}

bool messagequeue::empty()
{
    boost::shared_lock<boost::shared_mutex> lk(mtx);
    if (dataqueue.size()==0)
    {
        return false;
    } else 
    {
        return true;
    }
    }

}