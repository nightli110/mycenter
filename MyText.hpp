/*** 
 * @Author: nightli
 * @Date: 2020-10-12 20:05:38
 * @LastEditors: nightli
 * @LastEditTime: 2020-10-13 11:38:40
 * @FilePath: /mycenter/MyText.hpp
 * @Emile: 1658484908@qq.com
 */
#include <iostream>
#include <string>
using namespace std;

class TextInfo
{
public:
    TextInfo();

    TextInfo(string mystr);

    void SetText(string mystr);

    string GetText();

    void SetTextId(string myid);

    string GetTextId();

private:
    string MyText;

    string TextId;
}