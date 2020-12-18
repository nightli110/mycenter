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
    Imagecode = "";
    Height = 0;
    Width = 0;
}

ImageInfo::ImageInfo(string image, int height, int width)
{
    Imagecode = image;
    Height = height;
    Width = width;
}
ImageInfo::ImageInfo(string image)
{
    Imagecode = image;
    Height = 0;
    Width = 0;
}

void ImageInfo::SetImagePath(string path)
{
    Imagecode = path;
}

void ImageInfo::SetSize(int height, int width)
{
    Height = height;
    Width = width;
}

string ImageInfo::GetImagecode()
{
    return Imagecode;
}

pair<int, int> ImageInfo::GetSize()
{
    return pair<int, int>(Height, Width);
}