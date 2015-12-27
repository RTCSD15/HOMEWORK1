#include <iostream>
#include<Eigen/Dense>
#include<stdio.h>
#include<cmath>
#include<string>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace Eigen;  
using namespace std;

void Input(int n1,Vector2f &pt1,Vector2f &pt2,Vector2f &pt3)
{
	switch(n1){
		case 1:{
		scanf("%*c%*c%e%*c%e%*c%*c",&pt1[0],&pt1[1]);
		pt3=pt2=pt1;
		break;
		}
		case 2:{
		scanf("%*c%*c%e%*c%e%*c%*c%*c%e%*c%e%*c%*c",&pt1[0],&pt1[1],&pt2[0],&pt2[1]);
		pt3=pt2;
		break;
		}
		case 3:{
		scanf("%*c%*c%e%*c%e%*c%*c%*c%e%*c%e%*c%*c%*c%e%*c%e%*c%*c",&pt1[0],&pt1[1],&pt2[0],&pt2[1],&pt3[0],&pt3[1]);
		break;
		}
	}
			
} 
void move(Vector2f L ,Vector2f &pt1,Vector2f &pt2,Vector2f &pt3)
{
	pt1+=L;
	pt2+=L;
	pt3+=L;	
}
void rotate(float ang,Vector2f &pt1,Vector2f &pt2,Vector2f &pt3)
{
	MatrixXf m(2,2);
	m(0,0)=cos(ang*3.14/180);
	m(0,1)=-sin(ang*3.14/180);
	m(1,0)=sin(ang*3.14/180);
	m(1,1)=cos(ang*3.14/180);

	pt1=pt1.transpose()*m;
	pt2=pt2.transpose()*m;
	pt3=pt3.transpose()*m;	 
}

int main(int argc, char** argv) {
	char str[20],type[10],str1[20];
	int n;
	Vector2f v1,v2,v3,l;
	float angle;  
	
	printf("输入名称、点数："); 
	scanf("%s %d",str,&n);
	printf("%s",str);
	printf("以（x,y）的格式输入坐标点："); 
	Input(n,v1,v2,v3); 
	
	printf("输入变换类型（move/rotate）以及变换图形："); 
	scanf("%s %s",type,str1);
	printf("%s %s",type,str1);

	if(type[0]=='m'&&type[1]=='o'&&type[2]=='v'&&type[3]=='e'){
		printf("以（x,y）的格式输入坐标变换量：");
		scanf("%*c%*c%a%*c%a%*c%*c",&l[0],&l[1]);
		move(l,v1,v2,v3);
	}
	else if(type[0]=='r'&&type[1]=='o'&&type[2]=='t'&&type[3]=='a'&&type[4]=='t'&&type[5]=='e'){
		printf("输入旋转角度："); 
		scanf("%a",&angle);
		rotate(angle,v1,v2,v3);
	}
	
	std::cout<<"转换后坐标为："<<"v1:"<<endl<<v1<<endl<<"v2:"<<endl<<v2<<endl<<"v3:"<<endl<<v3<<endl;

	return 0;
}

