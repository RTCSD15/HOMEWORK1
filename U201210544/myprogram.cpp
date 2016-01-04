#include <iostream>
#include <stdlib.h>
#include <Eigen/Dense>
#include <math.h>
using namespace std;
using Eigen::MatrixXd;
MatrixXd select(char str[])
{
            MatrixXd b(1,2);
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
             
            b(0,0)=atof(a);
            for(i=j;i<=49&&str[i]!=')';i++);
            for(u=0;u<=10&&j!=i-1;u++)
            {
                j++;
                a[u]=str[j];
            }
            b(0,1)=atof(a);
            return b;
}
int main()
{
char Name[15];
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
MatrixXd spot1(1,2);
MatrixXd spot2(1,2);
MatrixXd spot3(1,2);
MatrixXd spot4(1,2);
cout<<"please input ";
cin>>Name;
cin>>n;
switch(n)
{
    case 1:
        {
            cin>>str1;
            spot1=select(str1);
        }
        break;
    case 2:
        {
            cin>>str1;
            spot1=select(str1);
            cin>>str2;
            spot2=select(str2);  
        }
        break;
    case 3:
        {
            cin>>str1;
            spot1=select(str1);
            cin>>str2;
            spot2=select(str2);
            cin>>str3;
            spot3=select(str3);
        }
        break;
    default:cout<<"output error";
  
}
cout<<"please input method of operation"<<endl;
cin>>str4;
if(str4[0]=='m'&&str4[1]=='o'&&str4[2]=='v'&&str4[3]=='e'&&str4[4]==0)
        {
        cin>>str5;
        cin>>str6;
        spot4=select(str6);
        if(n==1)
         {
           spot1=spot1+spot4;
           cout<<"("<<spot1<<")"<<endl;
         }
        else if(n==2)
             {
               spot1=spot1+spot4;   
               spot2=spot2+spot4;
               cout<<"("<<spot1<<")"<<"("<<spot2<<")"<<endl;
             }
        else
             {
               spot1=spot1+spot4;   
               spot2=spot2+spot4;
               spot3=spot3+spot4;
               cout<<"("<<spot1<<")"<<"("<<spot2<<")"<<"("<<spot3<<")"<<endl;
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
           spot1=spot1*rot;
           cout<<"("<<spot1<<")"<<endl;
         }
        else if(n==2)
             {
               spot1=spot1*rot;  
               spot2=spot2*rot;
              cout<<"("<<spot1<<")"<<"("<<spot2<<")"<<endl;
             }
        else
             {
               spot1=spot1*rot;  
               spot2=spot2*rot;
               spot3=spot3*rot;
               cout<<"("<<spot1<<")"<<"("<<spot2<<")"<<"("<<spot3<<")"<<endl;
             }
         
       }
else
    {
        cout<<"output error"<<endl;
    }  
return 0;
}
