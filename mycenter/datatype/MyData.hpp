/*** 
 * @Author: nightli
 * @Date: 2020-10-12 23:19:32
 * @LastEditors: nightli
 * @LastEditTime: 2020-10-14 16:36:52
 * @FilePath: /mycenter/MyData.hpp
 * @Emile: 1658484908@qq.com
 */
#include <iostream>
#include <map>
#include <boost/fiber/condition_variable.hpp>

#include "MyText.hpp"
#include "MyImage.hpp"
#include "../common/Common.hpp"

using namespace std;

//接受到json 包含需要推理的图像文本信息，此外还包含可能的其他信息如用户cookies之类的
// DataInfo 将json中和推理相关信息保存
class DataInfo
{
public:
DataInfo();
DataInfo(const DataInfo& inputdata);

bool Imageadd(ImageInfo myimageinfo);

bool Textadd(TextInfo myimageinfo);

bool OutImageadd(ImageInfo myimageinfo);

bool OutTextadd(TextInfo myimageinfo);

ImageInfo GetImageInfo(string key);

TextInfo GetTextInfo(string key);

bool UpdateImageList(string mykey, ImageInfo myimageinfo);

bool UpdateTextList(string mykey, TextInfo mytextinfo);

bool RemoveImage(string mykey);

bool RemoveText(string mykey);

int GetImageLen();

int GetTextLen();

void SetDataSession(string mysession);

void SetDataTime(string time);

string GetDataSession();

string GetDataTime();

void SetStatus(int status);

int GetStatus();

void DataGet() ;

void DataProcess();
private:
    map<string, ImageInfo> InImageList;//图片格式数据
    int InImageLen;
    map<string, TextInfo> InTextList;//文本格式数据
    int InTextLen;

    map<string, ImageInfo>OutImageList;
    int OutImageLen;
    map<string, TextInfo>OutTextList;
    int OutTextLen;
    string DataSession;
    string DataTime;
    int status;

    boost::condition_variable_any CondGet;
    boost::mutex CondMu;
    boost::shared_mutex DataMutex;
};

DataInfo JsonToDataInfo(Json::Value postdata);
Json::Value OutDataToJson(DataInfo data);