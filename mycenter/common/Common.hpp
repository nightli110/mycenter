/*** 
 * @Author: nightli
 * @Date: 2020-09-29 16:17:56
 * @LastEditors: nightli
 * @LastEditTime: 2020-10-13 22:05:51
 * @FilePath: /mycenter/Common.hpp
 * @Emile: 1658484908@qq.com
 */
#pragma once
#ifndef  _COMMOM_HPP
#define _COMMOM_HPP

#endif

#include <iostream>
#include <string>
#include <boost/thread/shared_mutex.hpp>
#include <glog/logging.h>
#include "json/json.h"

using namespace std;

enum inferencestatus
{
    registerd,
    online,
    offline,
    unregisterd
};

enum inferenceinput
{
    input_image,
    input_text
};

enum inferenceoutput
{
    output_image,
    output_text
};

struct returnmessage
{
    bool success;
    string failedmessage;
};

typedef boost::shared_lock<boost::shared_mutex> read_lock;
typedef boost::unique_lock<boost::shared_mutex> write_lock;

string JsonToString(const Json::Value &json);

Json::Value StringToJson(const std::string& str);

void PrintMonster();