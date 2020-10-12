/*** 
 * @Author: nightli
 * @Date: 2020-09-29 16:17:56
 * @LastEditors: nightli
 * @LastEditTime: 2020-10-12 19:17:21
 * @FilePath: /mycenter/Common.hpp
 * @Emile: 1658484908@qq.com
 */
#include <iostream>
#include <string>

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

string JsonToString(const Json::Value &json);

Json::Value StringToJson(const std::string& str);

void PrintMonster();