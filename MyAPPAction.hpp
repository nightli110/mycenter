#include <iostream>
#include <thread>

#include "InferenceAPP.hpp"
#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ptree.hpp>

class MyAPPActionView
{
public:
    MyAPPActionView(InferenceAPPMap *mymap);
    string Get(string request);

    string AppRegister(string requestjson);
    string AppUnRegister(string requestjson);
    string AppOnline(string requestjson);
    string AppOffLine(string requestjson);

private:
    InferenceAPPMap *appmap;
};