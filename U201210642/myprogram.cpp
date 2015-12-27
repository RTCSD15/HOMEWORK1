include <iostream>
#include<Eigen/Dense>
#include<stdlib.h>
#include<cmath>
using Eigen::MatrixXd;  
using namespace std;
MatrixXd input(char f[]){
   MatrixXd p(1,2);
   char a[256];
     char b[256];
     int x=0,y=0;
     int i,j;
     for(i=1;f[i]!=',';i++){
         a[x]=f[i];
         x++;
     }
     for(j=i+1;f[j]!=')';j++){
         b[y]=f[j];
         y++;
     }
     p(0,0)=atof(a);
     p(0,1)=atof(b);
     return p;
 }
 int main(){
     int n;
     char name[256];
     double deg,avg,PI=3.1415926;
     char f1[256],f2[256],f3[256],f4[256],f5[256],f6[256];
     MatrixXd rot(2,2);
     MatrixXd p1(1,2);
     MatrixXd p2(1,2);
     MatrixXd p3(1,2);
     MatrixXd p4(1,2);
     cout<<"请输入名称："<<endl;
     cin>>name;
     cout<<"请输入端点数：" <<endl;
     cin>>n;
     cout<<"请输入点坐标："<<endl;
     if(n==1){
        cin>>f1;
        p1=input(f1);
     }
     else if(n==2){
         cin>>f1;
         p1=input(f1);
         cin>>f2;
         p2=input(f2);
     }
     else if(n==3){
         cin>>f1;
         p1=input(f1);
         cin>>f2;
         p2=input(f2);
         cin>>f3;
         p3=input(f3);
     }
     else{
         cout<<"输入错误，请重新输入！"<<endl;
     }
     cout<<"请输入运算指令："<<endl;
     cin>>f4;
     cout<<"请输入名称："<<endl;
     cin>> f5;
     if(f4[0]=='m'&&f4[1]=='o'&&f4[2]=='v'&&f4[3]=='e'&&f4[4]==0){
         cout<<"请输入移动距离："<<endl;
         cin>>f6;
         p4=input(f6);
         if(n==1){
             p1+=p4;
             cout<<"("<<p1<<")"<<endl;
         }
         else if(n==2){
             p1+=p4;
             p2+=p4;
             cout<<"("<<p1<<")"<<"("<<p2<<")"<<endl;
         }
         else{
             p1+=p4;
             p2+=p4;
             p3+=p4;
             cout<<"("<<p1<<")"<<"("<<p2<<")"<<"("<<p3<<")"<<endl;
         }
     }
     else if(f4[0]=='r'&&f4[1]=='o'&&f4[2]=='t'&&f4[3]=='a'&&f4[4]=='t'&&f4[5]=='e'&&f4[6]==0){
         cout<<"请输入转动角度："<<endl;
         cin>>avg;
         deg=avg/180*PI;
         rot(0,0)=cos(deg);
         rot(0,1)=sin(deg);
         rot(1,0)=-sin(deg);
         rot(1,1)=cos(deg);
         if(n==1){
             p1*=rot;
             cout<<"("<<p1<<")"<<endl;
         }
         else if(n==2){
             p1*=rot;
             p2*=rot;
            cout<<"("<<p1<<")"<<"("<<p2<<")"<<endl;
        }
        else{
            p1*=rot;
            p2*=rot;
            p3*=rot;
            cout<<"("<<p1<<")"<<"("<<p2<<")"<<"("<<p3<<")"<<endl;
         }
     }
     return 0;
 }
