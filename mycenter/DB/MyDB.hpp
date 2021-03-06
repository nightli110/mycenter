/*
 * @Author: nightli
 * @Date: 2020-10-01 12:16:55
 * @LastEditors: nightli
 * @LastEditTime: 2020-10-12 17:02:36
 * @FilePath: /mycenter/MyDB.hpp
 * @Emile: 1658484908@qq.com
 */
#ifndef _MYDB_H
#define _MYDB_H
#include <iostream>
#include <string>
#include <mysql/mysql.h>
#include <glog/logging.h>
using namespace std;


class MyDB
{
public:
    MyDB();
    ~MyDB();
    bool initDB(string host, string user, string pwd, string db_name); //连接mysql
    bool exeSQL(string sql);                                           //执行sql语句
    bool fetch_result(string sql);
    void printresult(MYSQL_RES *result);
    MYSQL_RES *getmysqlresult();

private:
//TODO result不安全，重写MYDB
    MYSQL *mysql;      //连接mysql句柄指针
    MYSQL_RES *result; //指向查询结果的指针
    MYSQL_ROW row;     //按行返回的查询信息
};

#endif