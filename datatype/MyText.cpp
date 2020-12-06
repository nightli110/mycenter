/*** 
 * @Author: nightli
 * @Date: 2020-10-12 20:06:46
 * @LastEditors: nightli
 * @LastEditTime: 2020-10-13 11:40:03
 * @FilePath: /mycenter/MyText.cpp
 * @Emile: 1658484908@qq.com
 */
#include "MyText.hpp"

using namespace std;

TextInfo::TextInfo()
{
    MyText ="";
}

TextInfo::TextInfo(string text) 
{
    MyText = text;
}

void TextInfo::SetText(string text)
{
    MyText = text;
}

string TextInfo::GetText()
{
    return MyText;
} 

void TextInfo::SetTextId(string myid)
{
    TextId = myid;
}

string TextInfo::GetTextId()
{
    return TextId;
}