/*** 
 * @Author: nightli
 * @Date: 2020-10-11 15:41:53
 * @LastEditors: nightli
 * @LastEditTime: 2020-10-12 20:05:24
 * @FilePath: /mycenter/MyImage.cpp
 * @Emile: 1658484908@qq.com
 */
#include "MyImage.hpp"

using namespace std;

ImageInfo::ImageInfo()
{
    ImagePath = "";
    Height = 0;
    Width = 0;
}

ImageInfo::ImageInfo(string path, int height, int width)
{
    ImagePath = path;
    Height = height;
    Width = width;
}

void ImageInfo::SetImagePath(string path)
{
    ImagePath = path;
}

void ImageInfo::SetSize(int height, int width)
{
    Height = height;
    Width = width;
}

string ImageInfo::GetImagePath()
{
    return ImagePath;
}

pair<int, int> ImageInfo::GetSize()
{
    return pair<int, int>(Height, Width);
}