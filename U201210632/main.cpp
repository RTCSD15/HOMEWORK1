#include <iostream>
#include <stdlib.h>
#include <Eigen/Dense>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
using namespace Eigen; 

void find(char *strr,Vector2d &pt)
{
    int i=1,j=0;
    char s1[5],s2[5];
    for(;i<10&&strr[i]!=',';i++)
    {
        s1[j]=strr[i];
        pt[0]=atof(s1);j++;
    }
    i++;
    for(j=0;i<20&&strr[i]!=')';i++)
    {
        s2[j]=strr[i];
        pt[1]=atof(s2);j++;    
    }
}
void tt(int n1,Vector2d &pt1,Vector2d &pt2,Vector2d &pt3)
{
        char str1[20],str2[20],str3[20];
        switch(n1){
            case 3: {
                cin>>str3;
                find(str3,pt3);
            }
            case 2: {
                cin>>str2;
                find(str2,pt2);
            }    
            case 1: {
                cin>>str1;
                find(str1,pt1);
                break;
        }
            default:cout<<"输入错误"<<endl;
        }
                        
}


int main(int argc, char** argv) {
    char name[60],trans[20],name1[60],str[20],s[20];
    int n;
    double deg;
    Vector2d move,v1,v2,v3;
    MatrixXd rot(2,2);

    cout<<"请输入 ";
    cin>>name;
    cin>>n;
    tt(n,v1,v2,v3);
    cout<<"请输入操作指令"<<endl;
    cin>>trans;
    cin>>name1;
    if(trans[0]=='m'&&trans[1]=='o'&&trans[2]=='v'&&trans[3]=='e'&&trans[4]==0)
    {
        cin>>str;
        find(str,move);
        switch(n)
        {
        case 3:v3+=move;cout<<"("<<v3[0]<<","<<v3[1]<<")"<<endl;
        case 2:v2+=move;cout<<"("<<v2[0]<<","<<v2[1]<<")"<<endl;
        case 1:v1+=move;cout<<"("<<v1[0]<<","<<v1[1]<<")"<<endl;break;
        default: cout<<"输入出错"<<endl;
         
        }
    }
    else if(trans[0]=='r'&&trans[1]=='o'&&trans[2]=='t'&&trans[3]=='a'&&trans[4]=='t'&&trans[5]=='e'&&trans[6]==0)
    {
        cin>>deg;
        deg=deg*3.14/180;
        rot(0,0)=cos(deg);
        rot(0,1)=-sin(deg);
        rot(1,0)=sin(deg);
        rot(1,1)=cos(deg);
        
         switch(n)
        {
        case 3:v3=v3.transpose()*rot;cout<<"("<<v3[0]<<","<<v3[1]<<")"<<endl;
        case 2:v2=v2.transpose()*rot;cout<<"("<<v2[0]<<","<<v2[1]<<")"<<endl;
        case 1:v1=v1.transpose()*rot;cout<<"("<<v1[0]<<","<<v1[1]<<")"<<endl;break;
        default: cout<<"输入出错"<<endl;  
        }  
    }  
    return 0;
}
