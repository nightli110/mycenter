/*** 
 * @Author: nightli
 * @Date: 2020-10-11 15:41:44
 * @LastEditors: nightli
 * @LastEditTime: 2020-10-13 22:07:12
 * @FilePath: /mycenter/MyImage.hpp
 * @Emile: 1658484908@qq.com
 */

#include <iostream>

using namespace std;

class ImageInfo
{
public:
    ImageInfo();
    
    ImageInfo(string image, int height, int width);

    ImageInfo(string image);

    void SetImagecode(string image);

    void SetSize(int height, int width);

    string GetImagecode();

    pair<int, int> GetSize();

private:
    string Imagecode;
    int Height;
    int Width;
};