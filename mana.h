#include <iostream>
// #ifndef   MY_FILE_H
// #define MY_FILE_H
#include <string>
#include <fstream>
#include <vector>
#include "syud.h"
#include "ident.h"
#include "ident.h"
#include "teacher.h"

using namespace std;


class Manager :public identity{
    public:
            Manager();
            Manager(string name,string password){
                    cout<<"构成"<<endl;
                    this->name=name;
                    this->password=password;
                        initVector();//初始化容器
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
                        //这里检查是否又重复学号
                        bool a=this->checkre(sid,1);
                        if(a){
                                cout << "又重复的学生" << endl;
                        }
                        ofstream ofs;
                        ofs.open("student.txt",ios::out | ios::app);
                        ofs << sid << " "<< sname <<" "<< spwd<<endl;
                        cout<<"添加成功"<<endl;
                        ofs.close();
                    }
                    if (c==2)
                    {
                        /* 老师的操作 */
                    }
                    
                 //this->initVector();   
            };/* 添加用户 */
            void showperson(){  //这里是通过遍历容器来实现
                    cout << "--2显示用户 --" << endl;
                    cout <<"dsadsadasdasdas"<<endl;
                    int e;
                    cin >> e;
                    if(e==1){//学生
                        for (vector<stduent>:: iterator i = Su.begin(); i != Su.end(); i++)  //遍历容器   ------重要
                        {
                               // printstduent(**i);
                              cout <<i->id<<i->name<<i->password<<endl;
                                
                        }
                       // for_each(Su.begin(),Su.end(),printstduent);
                        
                    }else if (e==2)//老师
                    {
                            /* code */
                    }
                    

            };/* 显示用户 */
            
                void printteacher(teacher & c){ //指针来实现
                        cout <<c.tid<<c.name<<endl;
                };
                void printstduent(stduent & d){
                        cout <<d.id<<d.name<<endl;
                };







            void showcompuet(){
                    cout << "--3显示机房--" << endl;
            };/* 显示机房 */
            void cleanfile(){
                    cout << "--4清空文件 --" << endl;
            };/* 清空文件 */
            string name;
            string password;
        //初始化容器
        void initVector(){
                 ifstream ifs;
                ifs.open("student.txt",ios::in); 
                 if (!ifs.is_open())
                {
                         cout << "文件不纯在" << endl;
                          ifs.close();
                         return;
                 }
                 Su.clear();
                 Te.clear();
                 stduent s;
          while (ifs>>s.id && ifs>>s.name && ifs>>s.password)
          {
            Su.push_back(s);
           };
                cout << "输出当前学生数量" <<Su.size()<< endl;
        ifs.close();
        ifs.open("teacher.txt",ios::in); 
        teacher a;
                  while (ifs>>a.name && ifs>>a.password)
          {
            Te.push_back(a);
           };
                cout << "输出当前学生数量" <<Te.size()<< endl;

        };

        vector<stduent> Su;
        vector<teacher> Te;
        bool checkre(int a,int b){ //查询文件中是否又重复的人
                if (b==1)
                {
                        /* code */
                        for (vector<stduent>::iterator it = Su.begin(); it != Su.end(); it++)
                        {
                                if (a==it->id)
                                {
                                         return 1;     /* code */
                                }
                                
                        }
                        
                }
                
        }
};
