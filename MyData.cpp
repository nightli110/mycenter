/*** 
 * @Author: nightli
 * @Date: 2020-10-12 23:20:02
 * @LastEditors: nightli
 * @LastEditTime: 2020-10-13 22:20:52
 * @FilePath: /mycenter/MyData.cpp
 * @Emile: 1658484908@qq.com
 */
#include "MyData.hpp"

using namespace std;

DataInfo::DataInfo()
{
    InImageLen = 0;
    InTextLen = 0;
    OutImageLen = 0;
    OutTextLen = 0;
    status = 0;
}

bool DataInfo::Imageadd(ImageInfo myimageinfo)
{
    write_lock wlock(ImageMutex);
    string mykey = myimageinfo.GetImagePath();
    if (!InImageList.count(mykey))
    {
        InImageList[mykey] = myimageinfo;
        InImageLen++;
        return true;
    }
    else
    {
        cout << "key has already exit" << endl;
        return false;
    }
}

bool DataInfo::Textadd(TextInfo mytextinfo)
{
    write_lock wlock(TextMutex);
    string myid = mytextinfo.GetTextId();
    if (!InTextList.count(myid))
    {
        InTextList[myid] = mytextinfo;
        InTextLen++;
        return true;
    }
    else
    {
        cout << "id has alread exit" << endl;
        return false;
    }
}
   
ImageInfo DataInfo::GetImageInfo(string key)
{
    read_lock rlock(ImageMutex);
    if (InImageList.count(key))
    {
        return InImageList[key];
    }
    else
    {
        cout << "no key" << endl;
        return ImageInfo();
    }
}

TextInfo DataInfo::GetTextInfo(string key)
{
    read_lock rlock(TextMutex);
    if (InTextList .count(key))
    {
        return InTextList[key];
    }
    else
    {
        cout << "no key" << endl;
    }
}

bool DataInfo::UpdateImageList(string mykey, ImageInfo myimageinfo)
{
    write_lock wlock(ImageMutex);
    if (InImageList.count(mykey))
    {
        InImageList[mykey] = myimageinfo;
        return true;
    }
    else
    {
        cout << "update faild" << endl;
        return false;
    }
}

bool DataInfo::UpdateTextList(string mykey, TextInfo mytextinfo)
{
    write_lock wlock(TextMutex);
    if (InTextList.count(mykey))
    {
        InTextList[mykey] = mytextinfo;
        return true;
    }
    else
    {
        cout << "update faild" << endl;
        return false;
    }
}

bool DataInfo::RemoveImage(string mykey)
{
    write_lock wlock(ImageMutex);
    if (InImageList.count(mykey))
    {
        InImageList.erase(mykey);
        InImageLen--;
        return true;
    }
    else
    {
        cout << "remove faild" << endl;
        return false;
    }
}

bool DataInfo::RemoveText(string mykey)
{
    write_lock wlock(TextMutex);
    if (InImageList.count(mykey))
    {
        InImageList.erase(mykey);
        InTextLen--;
        return true;
    }
    else
    {
        cout << "remove faild" << endl;
        return false;
    }
}

int DataInfo::GetImageLen()
{
    return InImageLen;
}

int DataInfo::GetTextLen()
{
    return InTextLen;
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

bool DataInfo::OutImageadd(ImageInfo myimageinfo)
{
    write_lock wlock(ImageMutex);
    string mykey = myimageinfo.GetImagePath();
    if (!OutImageList.count(mykey))
    {
        OutImageList[mykey] = myimageinfo;
        OutImageLen++;
        return true;
    }
    else
    {
        cout << "key has already exit" << endl;
        return false;
    }
}

bool DataInfo::OutTextadd(TextInfo mytextinfo)
{
    write_lock wlock(TextMutex);
    string myid = mytextinfo.GetTextId();
    if (!OutTextList.count(myid))
    {
        OutTextList[myid]= mytextinfo;
        OutTextLen++;
        return true;
    }
    else
    {
        cout << "id has alread exit" << endl;
        return false;
    }
}
   