#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "glab.h"
#include <fstream>
#include "ident.h"
#include "syud.h"
#include "teacher.h"
#include "mana.h"
using namespace std;

void loginin(int type){
    identity * person = NULL;  //利用多态原理：创建父类指针 来创建子类对象
    ifstream ifs; //打开文件 读文件
    if (type==1)
    {
      ifs.open("student.txt",ios::in);  
    }
    if (type==2)
    {
      ifs.open("tracher.txt",ios::in);  
    }
    if (type==3)
    {
      ifs.open("admin.txt",ios::in);  
    }
    
   
    if (!ifs.is_open())
    {
         cout << "文件不纯在" << endl;
         ifs.close();
         return;
    }
    int id=0;
    string name;
    string pwd;
    if (type==1)
    {
        /* code */
        cout << "输入学号" << endl;
        cin >>id;
        cout << "输入账号" << endl;
        cin >> name;
        cout << "输入密码" << endl;
        cin >> pwd;
    int fid;
    string fname;
    string fpwd;
    while (ifs>>fid && ifs>>fname && ifs>>fpwd)
    {
        if(fid==id &&fname==name && fpwd==pwd){
            cout <<"登录成功"<<endl;
            person =new stduent(id,name,pwd);
           
            return;
        }
    }

    }
    if (type==2)
    {
        /* code */
         cout << "输入教师号" << endl;
         cin >>id;
         cout << "输入账号" << endl;
        cin >> name;
        cout << "输入密码" << endl;
        cin >> pwd;
    int fid;
    string fname;
    string fpwd;
    while (ifs>>fid && ifs>>fname && ifs>>fpwd)
    {
        if(fid==id &&fname==name && fpwd==pwd){
            cout <<"登录成功"<<endl;
            person =new teacher(id,name,pwd);
        }
    }
    }
    if (type==3)
    {
        /* code */
         cout << "输入管理员号" << endl;
         cin >>id;
         cout << "输入账号" << endl;
        cin >> name;
        cout << "输入密码" << endl;
        cin >> pwd;
    int fid;
    string fname;
    string fpwd;
    while (ifs>>fid && ifs>>fname && ifs>>fpwd)
    {
        if(fid==id &&fname==name && fpwd==pwd){
            cout <<"登录成功-----"<<endl;cout << "???????" << endl;
            person =new Manager(name,pwd);
            Manager* men=(Manager*)person;
            men->menu();
            int a;//接收输入
        cin >> a;
        if (a==1)
        {
            /* 添加账号 */
            men->addperson();
        }
        else if (a==2)
        {
            /* 查看账号 */
            men->showperson();
        }
        else if (a==3)
        {
            /* 查看机房 */
            men->showcompuet();
        }else if (a==4)
        {
            /* 清空文件 */
            men->cleanfile();
        }
        else{
            delete person;
            cout <<"注销"<< endl;
            return; 
        }
            //managmenu(person);
        }
    }
    }      
    cout << "失败" << endl;

}

// void managmenu(identity * &manager){ /* 用父类的指针（identity * ）来接收他 创建 */
//     while (true)
//     {
//         /* code */
//         manager->menu();
//         Manager* men=(Manager*)manager; /* 将父类指针 强转换成 子类指针  这样子就能使用子类的方法 */
//         int a;//接收输入
//         cin >> a;
//         if (a==1)
//         {
//             /* 添加账号 */
//             men->addperson();
//         }
//         else if (a==2)
//         {
//             /* 查看账号 */
//             men->showperson();
//         }
//         else if (a==3)
//         {
//             /* 查看机房 */
//             men->showcompuet();
//         }else if (a==4)
//         {
//             /* 清空文件 */
//             men->cleanfile();
//         }
//         else{
//             delete manager;
//             cout <<"注销"<< endl;
//             return; 
//         }
                
//     }
    
// }

int main()
{
    int select;
    bool a=1;
    while (a)
    {
        /*  */
    cout << "------Hello, world!------" << endl;
    cout << "输入你的身份" << endl;
    cout << "----------" << endl;
    cout << "--1学生 --" << endl;
    cout << "--2老师 --" << endl;
    cout << "--3管理员--" << endl;
    cout << "--4退出 --" << endl;
    cout << "----------" << endl;
    cout << "------------------------" << endl;

    cin >> select ;
    switch (select)
    {
    case 1:
        loginin(1);
        break;
    case 2:
        loginin(2);
        break;
    case 3:
       loginin(3);
        break;
    case 4:
        cout << "退出" << endl; 
            
        return 0;
        break;      
    
    default:
        cout << "请重新输入数字" << endl;
        system("pause");
        system("cln");
        break;
    }
    }
    return 0;
}

// class stduent :public identity{
//     public:
//             stduent(){
                    
//             };
//             stduent(int id, string name, string password){

//             };
//             virtual void meun(){

//             };/* 菜单 */
//             void  apply(){

//             };/* 申请 */
//             void  showapply(){

//             };/* 现实申请 */
//             void  showallorder(){

//             };/* 查看申请 */
//             void  cancelorder(){

//             };/* 取消申请 */
//             int id;

// };
// class teacher :public identity{
//     public:
//             teacher();
//             teacher(int tid,string name, string password);
//             virtual void meun();
//             void showorder();/* 查看申请 */
//             void validorder();/* 审核申请 */
//             int tid;

// };
// class manager :public identity{
//     public:
//             manager();
//             manager(string name,string password);
//             virtual void meun();
//             void addperson();/* 添加用户 */
//             void showperson();/* 显示用户 */
//             void showcompuet();/* 显示机房 */
//             void cleanfile();/* 清空文件 */
// };
