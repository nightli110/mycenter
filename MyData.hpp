/*** 
 * @Author: nightli
 * @Date: 2020-10-12 23:19:32
 * @LastEditors: nightli
 * @LastEditTime: 2020-10-13 16:18:22
 * @FilePath: /mycenter/MyData.hpp
 * @Emile: 1658484908@qq.com
 */
#include <iostream>
#include <map>

#include "MyText.hpp"
#include "MyImage.hpp"
#include "Common.hpp"

using namespace std;

class 
{
public:
DataInfo();
DataInfo
bool ImageMapadd(ImageInfo myimageinfo);

bool TextMapadd(TextMap myimageinfo);

ImageInfo GetImageInfo(string key);

TextInfo GetTextInfo(string key);

bool UpdateImageMap(string mykey, ImageInfo myimageinfo);

bool UpdateTextMap(string mykey, TextInfo mytextinfo);

bool RemoveImageMap(string mykey);

bool RemoveTextMap(string mykey);

int GetImageLen();

int GetTextLen();

void SetDataSession(string mysession);

void SetDataTime(string time);

string GetDataSession();

string GetDataTime();

void SetStatus(int status);

int GetStatus();

private:
    map<string, ImageInfo> ImageMap;
    int ImageMapLen;
    map<string, TextInfo> TextMap;
    int TextMapLen;
    string DataSession;
    string DataTime;
    int status;

    boost::shared_mutex ImageMutex;
    boost::shared_mutex TextMutex;
}