/*** 
 * @Author: nightli
 * @Date: 2020-10-11 15:41:44
 * @LastEditors: nightli
 * @LastEditTime: 2020-10-12 19:58:10
 * @FilePath: /mycenter/MyImage.hpp
 * @Emile: 1658484908@qq.com
 */

#include <iostream>

using namespace std;

class ImageInfo
{
public:
    ImageInfo();
    
    ImageInfo(string path, int height, int width);

    void SetImagePath(string path);

    void SetSize(int height, int width);

    string GetImagePath();

    pair<int, int> GetSize();

private:
    string ImagePath;
    int Height;
    int Width;
}