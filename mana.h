#include <iostream>
#include <string>
#include "ident.h"
using namespace std;


class Manager :public identity{
    public:
            Manager();
            Manager(string name,string password){
                    cout<<"构成"<<endl;
                    this->name=name;
                    this->password=password;


            };
            virtual void menu(){
                    cout<<"-----------"<<endl;
                        cout << "--1添加用户--" << endl;
                        cout << "--2显示用户 --" << endl;
                        cout << "--3显示机房--" << endl;
                        cout << "--4清空文件 --" << endl;
                    cout<<"-----------"<<endl;
            };
            void addperson(){
                int c;
                    cout << "--1添加学生用户--" << endl;
                    cout << "--2添加老师用户--" << endl;
                     
                    cin >> c;
                    if (c==1)
                    {
                        /* code */
                        int sid;
                        string sname;
                        string spwd;
                        cout << "--请输入id--" << endl;
                        cin >> sid;
                        cout << "--请输入name--" << endl;
                        cin >> sname;
                        cout << "--请输入pwd--" << endl;
                        cin >> spwd;
                        ofstream ofs;
                        ofs.open("student.txt",ios::out | ios::app);
                        ofs << sid << " "<< sname <<" "<< spwd<<endl;
                        cout<<"添加成功"<<endl;
                    }
                    if (c==2)
                    {
                        /* code */
                    }
                    
                    
            };/* 添加用户 */
            void showperson(){
                    cout << "--2显示用户 --" << endl;
            };/* 显示用户 */
            void showcompuet(){
                    cout << "--3显示机房--" << endl;
            };/* 显示机房 */
            void cleanfile(){
                    cout << "--4清空文件 --" << endl;
            };/* 清空文件 */
            string name;
            string password;

};