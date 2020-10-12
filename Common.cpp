/***
 * @Author: nightli
 * @Date: 2020-09-29 16:18:10
 * @LastEditors: nightli
 * @LastEditTime: 2020-10-12 17:08:38
 * @FilePath: /mycenter/Common.cpp
 * @Emile: 1658484908@qq.com
 */
#include "Common.hpp"

using namespace std;

std::string JsonToString(const Json::Value &json)
{
  Json::StreamWriterBuilder builder;
  return Json::writeString(builder, json);
}

Json::Value StringToJson(const std::string &str)
{
  Json::Value json;

  Json::CharReaderBuilder builder;
  std::stringstream stream(str);
  std::string errs;
  if (!Json::parseFromStream(builder, stream, &json, &errs))
  {
    std::cerr << errs << std::endl;
  }

  return json;
}

void PrintMonster()
{
  cout << "/*" << endl;
  cout << "*" << endl;
  cout << "* 　　┏┓　　　 ┏┓+ +" << endl;
  cout << "* 　┏━┛┻━━━━━━━┛┻┓ + +" << endl;
  cout << "* 　┃　　　　　　┃ 　   " << endl;
  cout << "* 　┃　　　━　　 ┃ ++ + + +" << endl;
  cout << "*  ██████━██████ ┃+" << endl;
  cout << "* 　┃　　　　　　┃ +" << endl;
  cout << "* 　┃　　　┻　 　┃" << endl;
  cout << "* 　┃　　　　　　┃ + +" << endl;
  cout << "* 　┗━┓　　　┏━━━┛" << endl;
  cout << "* 　　┃　　　┃　　　" << endl;
  cout << "* 　　┃　　　┃ + + + +" << endl;
  cout << "* 　　┃　　　┃" << endl;
  cout << "* 　　┃　　　┃ +  神兽保佑" << endl;
  cout << "* 　　┃　　　┃    代码无bug" << endl;
  cout << "* 　　┃　　　┃　　+　　　　　　　　　" << endl;
  cout << "* 　　┃　 　 ┗━━━━━━━━┓ + +" << endl;
  cout << "* 　　┃ 　　　　　　　┣┓" << endl;
  cout << "* 　　┃ 　　　　　　　┏┛" << endl;
  cout << "* 　　┗┓┓┏━━━━━━━━━┳┓┏┛ + + + +" << endl;
  cout << "* 　　 ┃┫┫       　┃┫┫" << endl;
  cout << "* 　　 ┗┻┛　       ┗┻┛+ + + +" << endl;
  cout << "* " << endl;
  cout << "*/" << endl;
  cout<<"MADE BY BUPT"<<endl;
}