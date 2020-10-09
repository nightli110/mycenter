#include <iostream>
#include <thread>

#include "InferenceAPP.hpp"
#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ptree.hpp>


class RegisterView 
{
public:
    RegisterView(InferenceAPPMap* mymap);
    string Get(string request);

    string Post(string requestjson);

private:
    

    InferenceAPPMap* appmap;
};