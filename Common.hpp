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