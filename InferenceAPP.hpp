#include <string>
#include <iostream>
#include <map>
#include <boost/thread/shared_mutex.hpp>
#include <mysql/mysql.h>

using namespace std;

struct inferenceAPP
{
    string id;
    string inference_name;
    string model_name;
    string register_time;
    string ip;
    int status;
    string inference_input;
    string inference_output;
    int model_status;
    double model_memery;
};

typedef boost::shared_lock<boost::shared_mutex> read_lock;
typedef boost::unique_lock<boost::shared_mutex> write_lock;

class InferenceAPPMap
{
public:
    bool MysqlResToAppMap(MYSQL_RES *result);

    inferenceAPP MysqlRowToApp(MYSQL_ROW row);

    string MysqlRowToName(MYSQL_ROW row);

    map<string, inferenceAPP> GetInferenceMap();

private:
    map<string, inferenceAPP> AppMap;

    boost::shared_mutex read_write_mutex;
    int Mapsize;
};