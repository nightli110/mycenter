
#include <stdio.h>
#include <string>
#include <iostream>
#include <sstream>
#include <curl/curl.h>
#include <glog/logging.h>

#include "json/json.h"

size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream);

Json::Value postmessage(string ip, Json::Vaule item);
