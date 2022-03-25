#pragma once
#include <iostream>
#include <string>
using namespace std;
class identity{
    public:
            virtual void menu() = 0;//纯虚函数 抽象类
            string name;
            string password;
};