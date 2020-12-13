/*
 * @Author: nightli
 * @Date: 2020-09-28 22:37:46
 * @LastEditors: nightli
 * @LastEditTime: 2020-10-12 17:03:04
 * @FilePath: /mycenter/MyAPPAction.hpp
 * @Emile: 1658484908@qq.com
 */
#include <iostream>
#include <thread>
#include <glog/logging.h>

#include "InferenceAPP.hpp"
#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ptree.hpp>

class MyAPPActionView
{
public:
    MyAPPActionView(InferenceAPPMap *mymap);
    string GetMap();

    string AppRegister(string requestjson);
    string AppUnRegister(string requestjson);
    string AppOnline(string requestjson);
    string AppOffLine(string requestjson);


private:
    InferenceAPPMap *appmap;
};