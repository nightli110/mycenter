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

DataInfo::DataInfo(const DataInfo& inputdata)
{
    write_lock wlock(DataMutex);
    InImageLen = inputdata.InImageLen;
    InImageList = inputdata.InImageList;
    InTextLen = inputdata.InTextLen;
    InTextList = inputdata.InTextList;
    OutImageLen = inputdata.OutImageLen;
    OutTextLen = inputdata.OutTextLen;
    status = inputdata.status;

}

bool DataInfo::Imageadd(ImageInfo myimageinfo, string imagename)
{
    write_lock wlock(DataMutex);
    if (!InImageList.count(imagename))
    {
        InImageList[imagename] = myimageinfo;
        InImageLen++;
        return true;
    }
    else
    {
        LOG(WARNING)<<"Imageadd key exit";
        return false;
    }
}

bool DataInfo::Textadd(TextInfo mytextinfo, string textname)
{
    write_lock wlock(DataMutex);
    if (!InTextList.count(textname))
    {
        InTextList[textname] = mytextinfo;
        InTextLen++;
        return true;
    }
    else
    {
        LOG(WARNING)<<"Imageadd key exit";
        return false;
    }
}
   
ImageInfo DataInfo::GetImageInfo(string key)
{
    read_lock rlock(DataMutex);
    if (InImageList.count(key))
    {
        return InImageList[key];
    }
    else
    {
        LOG(WARNING)<<"GetImageInfo no key ";
        return ImageInfo();
    }
}

TextInfo DataInfo::GetTextInfo(string key)
{
    read_lock rlock(DataMutex);
    if (InTextList .count(key))
    {
        return InTextList[key];
    }
    else
    {
        LOG(WARNING)<<"GetTextInfo no key ";
        return TextInfo();
    }
}

ImageInfo DataInfo::GetOutImageInf(string key)
{
    read_lock rlock(DataMutex);
    if (output_image.count(key))
    {
        return output_image[key];
    }
    else
    {
        LOG(WARNING)<<"GetOutImageInf no key ";
        return ImageInfo();
    }
}

TextInfo DataInfo::GetOutTextInfo(string key)
{

    read_lock rlock(DataMutex);
    if (OutTextList.count(key))
    {
        return OutTextList[key];
    }
    else
    {
        LOG(WARNING)<<"GetOutTextInfo no key ";
        return TextInfo();
    }
}

bool DataInfo::UpdateImageList(string mykey, ImageInfo myimageinfo)
{
    write_lock wlock(DataMutex);
    if (InImageList.count(mykey))
    {
        InImageList[mykey] = myimageinfo;
        return true;
    }
    else
    {
        LOG(WARNING)<<"UpdateImageList update faild";
        return false;
    }
}

bool DataInfo::UpdateTextList(string mykey, TextInfo mytextinfo)
{
    write_lock wlock(DataMutex);
    if (InTextList.count(mykey))
    {
        InTextList[mykey] = mytextinfo;
        return true;
    }
    else
    {
        LOG(WARNING)<<"UpdateTextList update faild";
        return false;
    }
}

bool DataInfo::RemoveImage(string mykey)
{
    write_lock wlock(DataMutex);
    if (InImageList.count(mykey))
    {
        InImageList.erase(mykey);
        InImageLen--;
        return true;
    }
    else
    {
        LOG(WARNING)<<"RemoveImage update faild";
        return false;
    }
}

bool DataInfo::RemoveText(string mykey)
{
    write_lock wlock(DataMutex);
    if (InImageList.count(mykey))
    {
        InImageList.erase(mykey);
        InTextLen--;
        return true;
    }
    else
    {
        LOG(WARNING)<<"RemoveText update faild";
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

bool DataInfo::OutImageadd(ImageInfo myimageinfo, string imagename)
{
    write_lock wlock(DataMutex);

    if (!OutImageList.count(imagename))
    {
        OutImageList[imagename] = myimageinfo;
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
    write_lock wlock(DataMutex);
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
   
DataInfo JsonToDataInfo(Json::Value postdata)
{
    DataInfo savedata;
    auto datalist = postdata["input"].asString();
    auto datanamelist = DataTypeSplit(datalist);
    regex pattern("(.*)_");
    smatch result;
    for (auto i : datanamelist)
    {
        string::const_iterator iterStart = i.begin();
        string::const_iterator iterEnd = i.end();
        regex_search(iterStart, iterEnd, result, pattern);
        if (result[0]=="image_")
        {
            ImageInfo tempimage(postdata[i].asString());
            savedata.Imageadd(tempimage, i);
            
        }
        else if (result[0]=="text_")
        {
            TextInfo temptext(postdata[i].asString());
            savedata.Textadd(postdata[i], i);

        }

    }

    savedata.SetDataTime(postdat["time"].asString());
    savedata.SetSession(postdata["userid"].asString());

    return savedata;
}

Json::Value OutDataToJson(DataInfo data)
{
    Json::Value returnjson;
    if (data.GetOutImageLen()>0)
    {
        for (int i=1; i<=data.GetOutImageLen(); i++)
        {
            string typename = "image_"  + to_string(i);
            returnjson[typename] = data.GetOutImageInfo(typename);
        }
    }

    if (data.GetOutTextLen()>0)
    {
        for (int i=1; i<data.GetOutTextLen(); i++)
        {
            string typename = "text_" + to_string(i);
            returnjson[typename] = data.GetOutTextInfo(typename);
        }
        

    }

    return returnjson;
}

vector<string> DataTypeSplit(string input)
{
    vector<string> datanames;
    vector<string> splitstr;

    boost::split(splitstr, input, boost::is_any_of(";"), boost::token_compress_on);

    for (auto i : splitstr)
    {
        vector<string> tempstr;
        boost::split(splitstr, i, boost::is_any_of(":"), boost::token_compress_on);
        if (tempstr.size()==2)
        {
            int typelen = atoi(tempstr[1].c_str());
            for (int j=1; j<=typelen; j++)
            {
                string dataname = tempstr[0] + "_" + to_string(j);
                datanames.push_back(dataname);
            }
        }
        else
        {
            LOG(ERROR)<<"Data type split list is error";
        }
    }
    return datanames;
}