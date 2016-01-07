#include <iostream>
#include <cstring>
#include<string>
#include <math.h>
#include <frames.hpp>        //orocos_kdl/src
#include <Eigen/Dense>       //Linear Algebra 
using Eigen::MatrixXd;
using namespace std;

class Point
{
	public:
	double x;
	double y;
	string name; 
	void movexy(MatrixXd p);//平移算子
	void rotang(double ang);//旋转算子 
};


void Point::movexy(MatrixXd p){
	cout<<x<<','<<y<<endl; 
	x+=p(0,0);y+=p(0,1);
	cout<<x<<','<<y<<endl; 
}
void Point::rotang(double deg){
	cout<<x<<','<<y<<endl; 
	    MatrixXd rot(2,2);//旋转矩阵 
	    rot(0,0)=cos(deg);
        rot(0,1)=sin(deg);
        rot(1,0)=-sin(deg);
        rot(1,1)=cos(deg);
        x=rot(0,0)*x+rot(0,1)*y;
        y=rot(1,0)*x+rot(1,1)*y;
        cout<<x<<','<<y<<endl; 
}
//点类定义完成

ostream&
operator << (ostream& os, const Point& X)
{
  return os << '(' << X.x << ',' << X.y << ')';
}
//重载运算符 
 
class Element
{
	public:
	char name[20];//名称 
	int n;
	Point pi[3];
	void Showelement(void);
};

void Element::Showelement(){
	cout<<name;
	int i;
	for(i=1;i<=n;i++)cout<<pi[i-1];
	cout<<endl;
}
//元素类定义完成 

Element Move(Element e,MatrixXd p){
	int i;
	for(i=1;i<=e.n;i++)e.pi[i-1].movexy(p);
	return e;
}
//元素平移 
Element Rotate(Element e,double deg){
	int i;
	for(i=1;i<=e.n;i++)e.pi[i-1].rotang(deg);
	cout<<"旋转命令已执行"<<endl;
	return e;
}
//元素旋转 

MatrixXd Getpoint(char str[]){
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
//从字符串获取点 

int main()
{
  MatrixXd p1(1,2),p2(1,2),p3(1,2),p4(1,2);
  //用于存放输入点以及位移向量 
  char str1[20],str2[20],str3[20],str4[20],str5[20],str6[20];
  double ang;
  Point P1,P2,P3,P4; 
  
  
  Element e1;
  cout<<"请输入元素(名称、点数、点坐标):";
  cin>> e1.name;
  cin>>e1.n;
  switch(e1.n){
  	case 1:
  		cin>>str1;p1=Getpoint(str1);e1.pi[0].x=p1(0,0), e1.pi[0].y=p1(0,1);
  		break;
    case 2:
    	cin>>str1;p1=Getpoint(str1);e1.pi[0].x=p1(0,0), e1.pi[0].y=p1(0,1);
    	cin>>str2;p2=Getpoint(str2);e1.pi[1].x=p2(0,0), e1.pi[1].y=p2(0,1);
  		break;
  	case 3:
  		cin>>str1;p1=Getpoint(str1);e1.pi[0].x=p1(0,0), e1.pi[0].y=p1(0,1);
  		cin>>str2;p2=Getpoint(str2);e1.pi[1].x=p2(0,0), e1.pi[1].y=p2(0,1);
  		cin>>str3;p3=Getpoint(str3);e1.pi[2].x=p3(0,0), e1.pi[2].y=p3(0,1);
  		break;
  	default:cout<<"输入错误";
  }
//根据点数获取内容并构造Element对象 


cout<<"请对当前输入元素输入操作命令：";
cin>>str4;cin>>str5;cin>>str6;
if(str4[0]=='m'&&str4[1]=='o'&&str4[2]=='v'&&str4[3]=='e'){
	cout<<"命令为move"<<endl;
	p4=Getpoint(str6);
	Element e2=Move(e1,p4);
	e2.Showelement();
}
if(str4[0]=='r'&&str4[1]=='o'&&str4[2]=='t'&&str4[3]=='a'&&str4[4]=='t'&&str4[5]=='e'&&str4[6]==0){
	ang=atof(str6)*3.1415926/180;
	cout<<"命令为rotate"<<endl;
	Element e2=Rotate(e1,ang);
	e2.Showelement();
}
  
 
  
}
