#include <iostream>
#include <stdlib.h>
#include <math.h>
#include "auxiliary.h"

using namespace std;
using Eigen::MatrixXd;

int main()
    {char name[3];
     int n;
     double deg;
     char Pt1Str[6];
     char Pt2Str[6];
     char Pt3Str[6];
     char Opr[7];
     char DispStr[6];          
     MatrixXd rot(2,2);
     MatrixXd Pt1(1,2);
     MatrixXd Pt2(1,2);
     MatrixXd Pt3(1,2);
     MatrixXd Disp(1,2);

     cout<<"初始化元素 ";
     cin>>name;
     cin>>n;
     switch(n)
         {case 1:
            {cin>>Pt1Str;
              Pt1=PtExt(Pt1Str);
            }
         break;
         case 2:
             {cin>>Pt1Str;
             Pt1=PtExt(Pt1Str);
             cin>>Pt2Str;
             Pt2=PtExt(Pt2Str);  
            }
         break;
         case 3:
             {cin>>Pt1Str;
             Pt1=PtExt(Pt1Str);
             cin>>Pt2Str;
             Pt2=PtExt(Pt2Str);
             cin>>Pt3Str;
             Pt3=PtExt(Pt3Str);
            }
         break;
         default:cout<<"输入错误";
         }

     cout<<"请输入操作指令"<<endl;
     cin>>Opr;
     if(Opr[0]=='m'&&Opr[1]=='o'&&Opr[2]=='v'&&Opr[3]=='e'&&Opr[4]==0)
         {cin>>name;
         cin>>DispStr;
         Disp=PtExt(DispStr);
         if(n==1)
             {Pt1=Pt1+Disp;
             cout<<"("<<Pt1<<")"<<endl;
            }
         else if(n==2)
             {Pt1=Pt1+Disp;   
             Pt2=Pt2+Disp;
             cout<<"("<<Pt1<<")"<<"("<<Pt2<<")"<<endl;
            }
         else
            {Pt1=Pt1+Disp;   
             Pt2=Pt2+Disp;
             Pt3=Pt3+Disp;
             cout<<"("<<Pt1<<")"<<"("<<Pt2<<")"<<"("<<Pt3<<")"<<endl;
            }
        }
     else if(Opr[0]=='r'&&Opr[1]=='o'&&Opr[2]=='t'&&Opr[3]=='a'&&Opr[4]=='t'&&Opr[5]=='e'&&Opr[6]==0)
         {cin>>name;
         cin>>deg;
         rot(0,0)=cos(deg);
         rot(0,1)=sin(deg);
         rot(1,0)=-sin(deg);
         rot(1,1)=cos(deg);
         if(n==1)
             {Pt1=Pt1*rot;
             cout<<"("<<Pt1<<")"<<endl;
            }
         else if(n==2)
             {Pt1=Pt1*rot;  
             Pt2=Pt2*rot;
             cout<<"("<<Pt1<<")"<<"("<<Pt2<<")"<<endl;
            }
         else
            {Pt1=Pt1*rot;  
             Pt2=Pt2*rot;
             Pt3=Pt3*rot;
             cout<<"("<<Pt1<<")"<<"("<<Pt2<<")"<<"("<<Pt3<<")"<<endl;
            }         
        }
     else
         {cout<<"输入出错"<<endl;
        }  
     return 0;
}

#include "auxiliary.h"

using Eigen::MatrixXd;

MatrixXd PtExt    (char str[])
    {MatrixXd p(1,2);
     p(0,0)=(float)str[1]-48;
     p(0,1)=(float)str[3]-48;
     return p;
    }
    
#ifndef __AUXILIARY
#define __AUXILIARY

#include <Eigen/Dense>

using Eigen::MatrixXd;

MatrixXd PtExt    (char str[]);

#endif
