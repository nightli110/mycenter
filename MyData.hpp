/*** 
 * @Author: nightli
 * @Date: 2020-10-12 23:19:32
 * @LastEditors: nightli
 * @LastEditTime: 2020-10-12 23:48:05
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
bool ImageMapadd(ImageInfo myimageinfo);

bool TextMapadd(TextMap myimageinfo);

private:
    map<int, ImageInfo> ImageMap;
    int ImageMapLen;
    map<int, TextInfo> TextMap;
    int TextMapLen;

    boost::shared_mutex ImageMutex;
    boost::shared_mutex TextMutex;
}