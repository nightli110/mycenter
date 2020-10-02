// #include<iostream>
// #include<map>

// using namespace std;



#include<iostream>
#include"MyDB.hpp"
using namespace std;


int main()
{
    MyDB db; 
    db.initDB("localhost","root","123456","application");
    db.exeSQL("SELECT * from app;");

    return 0;
}