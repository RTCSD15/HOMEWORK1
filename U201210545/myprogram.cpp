#include <iostream>
#include <stdlib.h>
#include <Eigen/Dense>
#include <math.h>
using namespace std;
using Eigen::MatrixXd;
MatrixXd select(char ast[])
{
MatrixXd point(1,2);
int w;
int i,j;
char a[10];
for(i=0;i<=49&&ast[i]!='(';i++);
for(j=0;j<=49&&ast[j]!=',';j++);
for(w=0;w<=10&&i!=j-1;w++)
{
i++;
a[w]=ast[i];
}

point(0,0)=atof(a);
for(i=j;i<=49&&ast[i]!=')';i++);
for(w=0;w<=10&&j!=i-1;w++)
{
j++;
a[w]=ast[j];
}
point(0,1)=atof(a);
return point;
}
int main()
{
char name[15];
int n;
double avg,deg;
float pi=3.14159265;
char ast1[20];
char ast2[20];
char ast3[20];
char ast4[15];
char ast5[15];
char ast6[15];
MatrixXd rot(2,2);
MatrixXd point1(1,2);
MatrixXd point2(1,2);
MatrixXd point3(1,2);
MatrixXd point4(1,2);
cout<<"Pkease input ";
cin>>name;
cin>>n;
switch(n)
{
case 1:
{
cin>>ast1;
point1=select(ast1);
}
break;
case 2:
{
cin>>ast1;
point1=select(ast1);
cin>>ast2;
point2=select(ast2); 
}
break;
case 3:
{
cin>>ast1;
point1=select(ast1);
cin>>ast2;
point2=select(ast2);
cin>>ast3;
point3=select(ast3);
}
break;
default:cout<<"ERROR";

}
cout<<"Please input"<<endl;
cin>>ast4;
if(ast4[0]=='m'&&ast4[1]=='o'&&ast4[2]=='v'&&ast4[3]=='e'&&ast4[4]==0)
{
cin>>ast5;
cin>>ast6;
point4=select(ast6);
if(n==1)
{
point1=point1+point4;
cout<<"("<<point1<<")"<<endl;
}
else if(n==2)
{
point1=point1+point4; 
point2=point2+point4;
cout<<"("<<point1<<")"<<"("<<point2<<")"<<endl;
}
else
{
point1=point1+point4; 
point2=point2+point4;
point3=point3+point4;
cout<<"("<<point1<<")"<<"("<<point2<<")"<<"("<<point3<<")"<<endl;
}
}
else if(ast4[0]=='r'&&ast4[1]=='o'&&ast4[2]=='t'&&ast4[3]=='a'&&ast4[4]=='t'&&ast4[5]=='e'&&ast4[6]==0)
{
cin>>ast5;
cin>>avg;
deg=avg/180*pi;
rot(0,0)=cos(deg);
rot(0,1)=sin(deg);
rot(1,0)=-sin(deg);
rot(1,1)=cos(deg);
if(n==1)
{
point1=point1*rot;
cout<<"("<<point1<<")"<<endl;
}
else if(n==2)
{
point1=point1*rot; 
point2=point2*rot;
cout<<"("<<point1<<")"<<"("<<point2<<")"<<endl;
}
else
{
point1=point1*rot; 
point2=point2*rot;
point3=point3*rot;
cout<<"("<<point1<<")"<<"("<<point2<<")"<<"("<<point3<<")"<<endl;
}

}
else
{
cout<<"ERROR"<<endl;
} 
return 0;
}
