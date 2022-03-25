#include <iostream>
#include <string>
#include "ident.h"
using namespace std;

class stduent :public identity{
    public:
            stduent(){
                    
            };
            stduent(int id, string name, string password){
                    cout<<"构成"<<endl;
            };
            virtual void menu(){
                    cout<<"重写纯虚函数"<<endl;
                    cout<<"构成"<<endl;
            };/* 菜单 */
            void  apply(){

            };/* 申请 */
            void  showapply(){

            };/* 现实申请 */
            void  showallorder(){

            };/* 查看申请 */
            void  cancelorder(){

            };/* 取消申请 */
            int id;

};