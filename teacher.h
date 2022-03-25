#include <iostream>
#include <string>
#include "ident.h"
using namespace std;

class teacher :public identity{
    public:
            teacher();
            teacher(int tid,string name, string password){
                    cout<<"构成"<<endl;
            };
            virtual void menu(){
                    cout<<"重写纯虚函数"<<endl;
                    cout<<"构成"<<endl;
            };
            void showorder();/* 查看申请 */
            void validorder();/* 审核申请 */
            int tid;

};