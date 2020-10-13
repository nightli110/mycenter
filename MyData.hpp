/*** 
 * @Author: nightli
 * @Date: 2020-10-12 23:19:32
 * @LastEditors: nightli
 * @LastEditTime: 2020-10-13 22:18:21
 * @FilePath: /mycenter/MyData.hpp
 * @Emile: 1658484908@qq.com
 */
#include <iostream>
#include <map>

#include "MyText.hpp"
#include "MyImage.hpp"
#include "Common.hpp"

using namespace std;

class DataInfo
{
public:
DataInfo();

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

private:
    map<string, ImageInfo>InImageList;
    int InImageLen;
    map<string, TextInfo> InTextList;
    int InTextLen;

    map<string, ImageInfo>OutImageList;
    int OutImageLen;
    map<string, TextInfo>OutTextList;
    int OutTextLen;
    string DataSession;
    string DataTime;
    int status;

    boost::shared_mutex ImageMutex;
    boost::shared_mutex TextMutex;
};