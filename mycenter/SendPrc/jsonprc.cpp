#include "jsonprc.hpp"

using namespace std;

size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream) 
{
    string data((const char*) ptr, (size_t) size * nmemb);

    *((stringstream*) stream) << data << endl;

    return size * nmemb;
}

Json::Value postmessage(string ip, Json::Value item)
{
    CURL *curl;
    CURLcode res;
    char tmp_str[256] = { 0 };
    std::stringstream out;

    struct curl_slist* headers = NULL;

    char *url = const_cast<char*>(ip.c_str());

    curl = curl_easy_init();

    if (curl)
    {
        Json::Reader Reader;
        Json::Value ReturnJson;

        string jsonout = item.toStyledString();

        curl_easy_setopt(curl, CURLOPT_URL, url);

        sprintf(tmp_str, "Content-Length: %s", jsonout.c_str());
        headers=curl_slist_append(headers, "Content-Type:application/json;charset=UTF-8");

        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(curl, CURLOPT_POST, 1);//设置为非0表示本次操作为POST


        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, jsonout.c_str());
        curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, jsonout.size());//设置上传json串长度,这个设置可以忽略

        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);//设置回调函数
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &out);//设置写数据
        res = curl_easy_perform(curl);//执行
        curl_slist_free_all(headers); /* free the list again */
        string str_json = out.str();
        LOG(INFO)<<str_json;
        Reader.parse(str_json, ReturnJson);
        return ReturnJson;
    } else 
    {
        Json::Value ReturnJson;
        LOG(INFO)<<"curl curl_easy_init failed";
        ReturnJson["error"]  ="curl curl_easy_init failed";
        return ReturnJson;
    }

}