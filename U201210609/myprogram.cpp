#include <iostream>
#include <stdlib.h>
#include <Eigen/Dense>
#include <math.h>
using namespace std;
using Eigen::MatrixXd;
MatrixXd extract(char str[])
{
            MatrixXd p(1,2);
            int u;
            int i,j;
            char a[10];
            for(i=0;i<=49&&str[i]!='(';i++);
            for(j=0;j<=49&&str[j]!=',';j++);
            for(u=0;u<=10&&i!=j-1;u++)
            {
                i++;
                a[u]=str[i];
            }
             
            p(0,0)=atof(a);
            for(i=j;i<=49&&str[i]!=')';i++);
            for(u=0;u<=10&&j!=i-1;u++)
            {
                j++;
                a[u]=str[j];
            }
            p(0,1)=atof(a);
            return p;
}
int main()
{
char name[15];
int n;
double avg,deg;
float pi=3.14159265;
char str1[20];
char str2[20];
char str3[20];
char str4[15];
char str5[15];
char str6[15];
MatrixXd rot(2,2);
MatrixXd p1(1,2);
MatrixXd p2(1,2);
MatrixXd p3(1,2);
MatrixXd p4(1,2);
cout<<"请输入 ";
cin>>name;
cin>>n;
switch(n)
{
    case 1:
        {
            cin>>str1;
            p1=extract(str1);
        }
        break;
    case 2:
        {
            cin>>str1;
            p1=extract(str1);
            cin>>str2;
            p2=extract(str2);  
        }
        break;
    case 3:
        {
            cin>>str1;
            p1=extract(str1);
            cin>>str2;
            p2=extract(str2);
            cin>>str3;
            p3=extract(str3);
        }
        break;
    default:cout<<"输入错误";
  
}
cout<<"请输入操作指令"<<endl;
cin>>str4;
if(str4[0]=='m'&&str4[1]=='o'&&str4[2]=='v'&&str4[3]=='e'&&str4[4]==0)
        {
        cin>>str5;
        cin>>str6;
        p4=extract(str6);
        if(n==1)
         {
           p1=p1+p4;
           cout<<"("<<p1<<")"<<endl;
         }
        else if(n==2)
             {
               p1=p1+p4;   
               p2=p2+p4;
               cout<<"("<<p1<<")"<<"("<<p2<<")"<<endl;
             }
        else
             {
               p1=p1+p4;   
               p2=p2+p4;
               p3=p3+p4;
               cout<<"("<<p1<<")"<<"("<<p2<<")"<<"("<<p3<<")"<<endl;
             }
        }
else if(str4[0]=='r'&&str4[1]=='o'&&str4[2]=='t'&&str4[3]=='a'&&str4[4]=='t'&&str4[5]=='e'&&str4[6]==0)
       {
        cin>>str5;
        cin>>avg;
        deg=avg/180*pi;
        rot(0,0)=cos(deg);
        rot(0,1)=sin(deg);
        rot(1,0)=-sin(deg);
        rot(1,1)=cos(deg);
        if(n==1)
         {
           p1=p1*rot;
           cout<<"("<<p1<<")"<<endl;
         }
        else if(n==2)
             {
               p1=p1*rot;  
               p2=p2*rot;
              cout<<"("<<p1<<")"<<"("<<p2<<")"<<endl;
             }
        else
             {
               p1=p1*rot;  
               p2=p2*rot;
               p3=p3*rot;
               cout<<"("<<p1<<")"<<"("<<p2<<")"<<"("<<p3<<")"<<endl;
             }
         
       }
else
    {
        cout<<"输入出错"<<endl;
    }  
return 0;
}
