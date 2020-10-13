/*** 
 * @Author: nightli
 * @Date: 2020-10-12 23:20:02
 * @LastEditors: nightli
 * @LastEditTime: 2020-10-13 17:09:21
 * @FilePath: /mycenter/MyData.cpp
 * @Emile: 1658484908@qq.com
 */
#include "MyData.hpp"

using namespace std;

DataInfo::DataInfo()
{
    ImageMapLen = 0;
    TextMapLen = 0;
    status=0;
}

bool DataInfo::ImageMapadd(ImageInfo myimageinfo)
{
    write_lock wlock(ImageMutex);
    string mykey = myimageinfo.GetImagePath();
    if (!ImageMap.count(mykey))
    {
        ImageMap[mykey] = myimageinfo;
        return true;
    }
    else
    {
        cout<<"key has already exit"<<endl;
        return false;
    }
    
}

bool DataInfo::TextMapadd(TextInfo mytextinfo)
{
    write_lock wlock(TextMutex);
    string myid = mytextinfo.GetTextId;
    if (!TextMap.count(myid))
    {
        TextMap(myid) = mytextinfo;
        return true;
    }
    else
    {
        cout<<"id has alread exit"<<ednl;
        return false;
    }
    
}


ImageInfo DataInfo::GetImageInfo(string key)
{
    read_lock rlock(ImageMutex);
    if (ImageMap.count(key))
    {
        return ImageMap[key];
    }
    else
    {
        cout<<"no key"<<endl;    
        return ImageInfo();
    }
    
}

TextInfo DataInfo::GetTextInfo(string key)
{
    read_lock rlock(TextMutex);
    if(TextInfo.count(key))
    {
        return TextMap[key];
    }
    else
    {
        cout<<"no key"<<endl;
    }
}

bool DataInfo::UpdateImageMap(string mykey, ImageInfo myimageinfo)
{
    write_lock wlock(ImageMutex);
    if (ImageMap.count(key))
    {
        ImageMap[mykey] = myimageinfo;
        return true;
    }
    else
    {
        cout<<"update faild"<<endl;
        return false;
    }    
}

bool DataInfo::UpdateTextMap(string mykey, TextInfo mytextinfo)
{
    write_lock wlock(TextMutex);
    if(TextMap.count(key))
    {
        TextMap[mykey] = mytextinfo;
        return true;
    }
    else
    {
        cout<<"update faild"<<endl;
        return false;
    }
}

bool DataInfo::RemoveImageMap(string mykey)
{
     write_lock wlock(ImageMutex);
    if(ImageMap.count(mykey))
    {
        ImageMap.ease(mykey);
        return true;
    } 
    else
    {
        cout<<"remove faild"<<endl;
        return false;
    }
}

bool DataInfo::RemoveTextMap(string key)
{
     write_lock wlock(TextMutex);
    if(TextMap.count(mykey))
    {
        TextMap.count(mykey);
        return true;
    }
    else
    {
        cout<<"remove faild"<<endl;
        rreturn false;
    }
}

int DataInfo::GetImageLen()
{
    return ImageMapLen;
}

int DataInfo::GetTextLen()
{
    return TextLen();
}

void DataInfo::SetDataSession(string mysession)
{
    DataSession = mysession;
}

void DataInfo::SetDataTime(string time)
{
    DataTime = time;
}

string DataInfo::GetDataSession()
{
    return DataSession;
}

string DataInfo::GetDataTime()
{
    return DataTime;
}

