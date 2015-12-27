#include <iostream>
#include <Eigen/Dense>
#include <cmath>
using Eigen::MatrixXd;
using namespace std;
float pi=3.1415926;
void mpoint(MatrixXd m)
{
	MatrixXd T(1,2),A(1,2);
	cout<<"请输入移动距离：";
	fflush(stdin);
	scanf("%*c%lf%*c%lf%*c",&T(0,0),&T(0,1)); 
	A=m+T;
	cout<<'('<<A(0,0)<<','<<A(0,1)<<')'; 
}

void rpoint(MatrixXd m)
{
	MatrixXd R(2,2),A(1,2);
	double ang;
	cout<<"请输入旋转角度：";
	fflush(stdin);
	cin>>ang;
	R(0,0)=cos(ang/180*pi);R(0,1)=sin(ang/180*pi);R(1,0)=-sin(ang/180*pi);R(1,1)=cos(ang/180*pi);
	A=m*R;
	cout<<'('<<A(0,0)<<','<<A(0,1)<<')';
}

void mline(MatrixXd m,MatrixXd n)
{
	MatrixXd T(1,2),A1(1,2),A2(1,2);
	cout<<"请输入移动距离：";
	fflush(stdin);
	scanf("%*c%lf%*c%lf%*c",&T(0,0),&T(0,1));
	A1=m+T;
	A2=n+T;
	cout<<'('<<A1(0,0)<<','<<A1(0,1)<<')'<<' '<<'('<<A2(0,0)<<','<<A2(0,1)<<')'; 
}

void rline(MatrixXd m,MatrixXd n)
{
	MatrixXd R(2,2),A1(1,2),A2(1,2);
	double ang;
	cout<<"请输入旋转角度：";
	fflush(stdin);
	cin>>ang;
	R(0,0)=cos(ang/180*pi);R(0,1)=sin(ang/180*pi);R(1,0)=-sin(ang/180*pi);R(1,1)=cos(ang/180*pi);
	A1=m*R;
	A2=n*R;
	cout<<'('<<A1(0,0)<<','<<A1(0,1)<<')'<<' '<<'('<<A2(0,0)<<','<<A2(0,1)<<')'; 
}

void mtriangle(MatrixXd m,MatrixXd n,MatrixXd k)
{
	MatrixXd T(1,2),A1(1,2),A2(1,2),A3(1,2);
	cout<<"请输入移动距离：";
	fflush(stdin);
	scanf("%*c%lf%*c%lf%*c",&T(0,0),&T(0,1));
	A1=m+T;
	A2=n+T;
	A3=k+T;
	cout<<'('<<A1(0,0)<<','<<A1(0,1)<<')'<<' '<<'('<<A2(0,0)<<','<<A2(0,1)<<')'<<' '<<'('<<A3(0,0)<<','<<A3(0,1)<<')'; 
}

void rtriangle(MatrixXd m,MatrixXd n,MatrixXd k)
{
	MatrixXd R(2,2),A1(1,2),A2(1,2),A3(1,2);
	double ang;
	cout<<"请输入旋转角度：";
	fflush(stdin);
	cin>>ang;
	R(0,0)=cos(ang/180*pi);R(0,1)=sin(ang/180*pi);R(1,0)=-sin(ang/180*pi);R(1,1)=cos(ang/180*pi);
	A1=m*R;
	A2=n*R;
	A3=k*R;
	cout<<'('<<A1(0,0)<<','<<A1(0,1)<<')'<<' '<<'('<<A2(0,0)<<','<<A2(0,1)<<')'<<' '<<'('<<A3(0,0)<<','<<A3(0,1)<<')'; 
}

void point()
{
	MatrixXd m(1,2);
	char cal[21];
	int a;
	cout<<"请输入点坐标：";
	fflush(stdin);
	scanf("%*c%lf%*c%lf%*c",&m(0,0),&m(0,1));
	a:
	cout<<"请输入运算指令：";
	cin>>cal;
	if(cal[0]=='m'&&cal[1]=='o'&&cal[2]=='v'&&cal[3]=='e'&&cal[4]==0)
	{
		mpoint(m);
	}
	else if(cal[0]=='r'&&cal[1]=='o'&&cal[2]=='t'&&cal[3]=='a'&&cal[4]=='t'&&cal[5]=='e'&&cal[6]==0)
	{
		rpoint(m);
	}
	else
	{
		cout<<"指令错误！"<<endl;
		goto a; 
	}
 
}

void line()
{
	MatrixXd m(1,2),n(1,2);
	char cal[21];
	int a;
	cout<<"请输入直线端点坐标：";
	fflush(stdin);
    scanf("%*c%lf%*c%lf%*c %*c%lf%*c%lf%*c",&m(0,0),&m(0,1),&n(0,0),&n(0,1));
    a:
    cout<<"请输入运算指令：";
    cin>>cal;
	if(cal[0]=='m'&&cal[1]=='o'&&cal[2]=='v'&&cal[3]=='e'&&cal[4]==0)
	{
		mline(m,n);
	}
	else if(cal[0]=='r'&&cal[1]=='o'&&cal[2]=='t'&&cal[3]=='a'&&cal[4]=='t'&&cal[5]=='e'&&cal[6]==0)
	{
		rline(m,n);
	}
	else
	{
		cout<<"指令错误！"<<endl;
		goto a; 
	}
}

void triangle()
{
	MatrixXd m(1,2),n(1,2),k(1,2);
	char cal[21];
	int a;
	cout<<"请输入三角形端点坐标：";
	fflush(stdin);
	scanf("%*c%lf%*c%lf%*c %*c%lf%*c%lf%*c %*c%lf%*c%lf%*c",&m(0,0),&m(0,1),&n(0,0),&n(0,1),&k(0,0),&k(0,1));
	a:
	cout<<"请输入运算指令：";
	cin>>cal;
	if(cal[0]=='m'&&cal[1]=='o'&&cal[2]=='v'&&cal[3]=='e'&&cal[4]==0)
	{
		mtriangle(m,n,k);
	}
	else if(cal[0]=='r'&&cal[1]=='o'&&cal[2]=='t'&&cal[3]=='a'&&cal[4]=='t'&&cal[5]=='e'&&cal[6]==0)
	{
		rtriangle(m,n,k);
	}
	else
	{
		cout<<"指令错误！"<<endl;
		goto a; 
	}
} 

int main()
{
	char name[11];
	int i;
	cout<<"请输入一个图形名称及其端点数：";
	cin.getline(name,10);
	for(i=0;i<11;i++)
	{
		if(name[i]==' ')break;
	}
	if(name[i+1]=='1')
	{
		point();
	}
	else if(name[i+1]=='2')
	{
		line();
	}
	else if(name[i+1]=='3')
	{
		triangle();
	}
	return 0;
}
