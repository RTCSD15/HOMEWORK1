#include <iostream>
#include <string>
#include <stdlib.h> 
#include <math.h>
#include <Eigen/Dense>

#define PN 100//可保存的点的数目 
#define LN 100//可保存线的数目 
#define RN 100//可保存三角形的数目 
#define PI 3.1415926

using namespace Eigen;
using namespace std;

void add ();
void addPoint();
void addLine();
void addRect();
void move();
void rotate();



//模板函数：将string类型变量转换为常用的数值类型（此方法具有普遍适用性）  
template <class Type>  
Type stringToNum(const string& str)  {  
    istringstream iss(str);  
    Type num;  
    iss >> num;  
    return num;      
}  

class Point {
	
	private :
		Vector2d v;	
		string name;	
	public:
		//构造函数
		Point(Vector2d v1){
			v = v1;
		}
		
		Point(Vector2d v1 , string pname) {
			v = v1;
			name = pname;
		} 
		
		Point() {};
		
		//设置点的x，y坐标 
		void setPoint(Vector2d v1){
			v = v1;
		}
				
		
		Vector2d getPoint() {
			return v;
		}
		
		string getName() {
			return name;
		}
		
		void setName(string pname) {
			name = pname;
		}
};

class Line {
	private :
		Vector2d v1;
		Vector2d v2;
		string name;
		
	public :
		//构造函数
		Line() {};
		 
		void setLine(Vector2d vv1,Vector2d vv2) {
			v1 = vv1;
			v2 = vv2;
		}
		
		Vector2d getStartPoint() {
			return v1;
		}
		
		Vector2d getEndPoint() {
			return v2;
		}
		
		void setName(string lname) {
			name = lname;
		}
		
		string getName() {
			return name;
		}		
};

class Rect {
	private :
		Vector2d v1;
		Vector2d v2;
	 	Vector2d v3;
	 	string name;
	 	
	public:
		Rect() {};
		
	void setRect(Vector2d vv1,Vector2d vv2,Vector2d vv3) {
		v1 = vv1;
		v2 = vv2;
		v3 = vv3;
	}
	
	Vector2d getPoint1() {
		return v1;
	}
	
	Vector2d getPoint2() {
		return v2;
	}
	
	Vector2d getPoint3() {
		return v3;
	}
	
	void setName(string rname) {
		name = rname;
	}
	
	string getName() {
		return name;
	}
};

string a[5];
int pcnt = 0;
Point point[PN]; 
int lcnt = 0;
Line line[LN];
int rcnt = 0;
Rect rect[RN];


int main(int argc,char *argv[]) {
	
	while(1) {
		string str ; //定义一个字符串去接收命令行传入的值
		getline(cin,str);//接收命令行的字符串 
		
	//将命令行的字符串按空格分割存入a[5]中 
		for(int i=0,j=0;i<str.size();i++) {
			int pos;
			pos = str.find(' ',i);
			if(pos!=std::string::npos) {
				a[j] = str.substr(i,pos-i);
				j++;
				i=pos;
			} else {
				a[j] = str.substr(i,str.size()-i);
				break;
			}
			
	 	}
	 	
	 	if(a[0]=="move") {
	 		move();
		} else if(a[0]=="rotate") {
			rotate();
		} else {
			add();
		}
	}
	
}

void add() {
	if(a[1]=="1") {
		addPoint();
	} else if(a[1]=="2") {
		addLine();
	} else if(a[1]=="3") {
		addRect();
	} else {
		cout<<"输入格式有误，请按照正确的格式输入！"<<endl;
	}
	
}

void addPoint() {
	Vector2d v;
	string m1,m2; 
	string s = a[2];
	double x,y;
	int pos;
	pos=s.find(',',0);
	if(pos!=std::string::npos) {
		m1 = s.substr(0,pos);
		m2 = s.substr(pos+1,s.size()-pos);
		x = stringToNum<double>(m1);
		y = stringToNum<double>(m2);
	 } else {
	 	cout<<"指令输入有误，要添加点请按照如下结构输入："<<endl;
	 	cout<<"p1 1 5.2,6.4"<<endl;
	 	exit(0); 
	 }
	 v<<x,y;
	 
	point[pcnt].setPoint(v);
	point[pcnt].setName(a[0]);
	pcnt++;
	cout<<"添加了一个点:"<<a[0]<<endl;
	cout<<"坐标为:"<<v.transpose()<<endl; 
	
}

void addLine() {
	Vector2d v1,v2;
	string m1,m2,m3,m4;
	string s1 = a[2];
	string s2 = a[3];
	double x1,x2,y1,y2;
	int pos1,pos2;
		pos1=s1.find(',',0);
		
	if(pos1!=std::string::npos) {
		m1 = s1.substr(0,pos1);
		m2 = s1.substr(pos1+1,s1.size()-pos1);
		x1 = stringToNum<double>(m1);
		y1 = stringToNum<double>(m2);
	 } else {
	 	cout<<"指令输入有误，要添加点请按照如下结构输入："<<endl;
	 	cout<<"l1 2 1,2 3,4"<<endl;
	 	exit(0); 
	}
	
	pos2=s2.find(',',0);
	if(pos2!=std::string::npos) {
		m3 = s2.substr(0,pos2);
		m4 = s2.substr(pos2+1,s2.size()-pos2);
		x2 = stringToNum<double>(m3);
		y2 = stringToNum<double>(m4);
	 } else {
	 	cout<<"指令输入有误，要添加点请按照如下结构输入："<<endl;
	 	cout<<"l1 2 1,2 3,4"<<endl;
	 	exit(0); 
	}
	
	v1<<x1,y1;
	v2<<x2,y2;
	line[lcnt].setLine(v1,v2);
	line[lcnt].setName(a[0]);
	lcnt++;
	cout<<"添加了一条线:"<<a[0]<<endl;
	cout<<"起点坐标为:"<<v1.transpose()<<endl;
	cout<<"终点坐标为:"<<v2.transpose()<<endl; 
}

void addRect() {
	Vector2d v1,v2,v3;
	string m1,m2,m3,m4,m5,m6;
	string s1 = a[2];
	string s2 = a[3];
	string s3 = a[4];
	double x1,x2,x3,y1,y2,y3;
	int pos1,pos2,pos3;
	
	pos1=s1.find(',',0);	
	if(pos1!=std::string::npos) {
		m1 = s1.substr(0,pos1);
		m2 = s1.substr(pos1+1,s1.size()-pos1);
		x1 = stringToNum<double>(m1);
		y1 = stringToNum<double>(m2);
	 } else {
	 	cout<<"指令输入有误，要添加点请按照如下结构输入："<<endl;
	 	cout<<"l1 2 1,2 3,4 5,6"<<endl;
	 	exit(0); 
	}
	
	pos2=s2.find(',',0);
	if(pos2!=std::string::npos) {
		m3 = s2.substr(0,pos2);
		m4 = s2.substr(pos2+1,s2.size()-pos2);
		x2 = stringToNum<double>(m3);
		y2 = stringToNum<double>(m4);
	 } else {
	 	cout<<"指令输入有误，要添加点请按照如下结构输入："<<endl;
	 	cout<<"l1 2 1,2 3,4"<<endl;
	 	exit(0); 
	}
	
	pos3=s3.find(',',0);
	if(pos3!=std::string::npos) {
		m5 = s3.substr(0,pos3);
		m6 = s3.substr(pos3+1,s3.size()-pos3);
		x3 = stringToNum<double>(m5);
		y3 = stringToNum<double>(m6);
	 } else {
	 	cout<<"指令输入有误，要添加点请按照如下结构输入："<<endl;
	 	cout<<"l1 2 1,2 3,4 5,6"<<endl;
	 	exit(0); 
	}
	
	v1<<x1,y1;
	v2<<x2,y2;
	v3<<x3,y3;
	rect[rcnt].setRect(v1,v2,v3);
	rect[rcnt].setName(a[0]);
	rcnt++;
	cout<<"添加了一个三角形:"<<a[0]<<endl;
	cout<<"端点一坐标为："<<v1.transpose()<<endl;
	cout<<"端点二坐标为："<<v2.transpose()<<endl;
	cout<<"端点三坐标为："<<v3.transpose()<<endl;
	 
}

void move() {
	string s;
	s = a[1];
	Vector2d v;
	bool find = false;
	string s1 = a[2];
	double x,y;
	int pos;
	string m1,m2;
	
	pos=s1.find(',',0);
	if(pos!=std::string::npos) {
		m1 = s1.substr(0,pos);
		m2 = s1.substr(pos+1,s.size()-pos);
		x = stringToNum<double>(m1);
		y = stringToNum<double>(m2);
	 } else {
	 	cout<<"指令输入有误，要添加点请按照如下结构输入："<<endl;
	 	cout<<"move XX 2,3"<<endl;
	 	exit(0); 
	 }
	 v<<x,y;
	
	for(int i=0;i<PN;i++) {
		if(point[i].getName()==s) {
			find = true;
			Vector2d v1 = point[i].getPoint();
			 v1=v1+v;
			 cout<<s<<"平移后的点的坐标为:"<<v1.transpose()<<endl;	
		} 
	}
	
	for(int i=0;i<LN;i++) {
		if(line[i].getName()==s) {
			find = true;
			Vector2d v1 = line[i].getStartPoint();
			Vector2d v2 = line[i].getEndPoint();
			 v1 = v1+v;
			 v2 = v2+v; 
			 cout<<"直线"<<s<<"平移后起点的坐标为:"<<v1.transpose()<<endl;
			 cout<<"直线"<<s<<"平移后终点的坐标为:"<<v2.transpose()<<endl;	
		} 
	}
	
	for(int i=0;i<RN;i++) {
		if(rect[i].getName()==s) {
			find = true;
			Vector2d v1 = rect[i].getPoint1();
			Vector2d v2 = rect[i].getPoint2();
			Vector2d v3 = rect[i].getPoint3();
			 v1 = v1+v;
			 v2 = v2+v; 
			 v3 = v3+v;
			 cout<<"三角形"<<s<<"点1平移后的坐标为:"<<v1.transpose()<<endl;
			 cout<<"三角形"<<s<<"点2平移后的坐标为:"<<v2.transpose()<<endl;
			 cout<<"三角形"<<s<<"点3平移后的坐标为:"<<v2.transpose()<<endl;	
		} 
	}
	
	if(find==false) {
		cout<<"没有找到对应的点线面，请先添加点线面！"<<endl; 
	}
}

void rotate() {
	string s;
	string s1 = a[2];
	s = a[1];
	MatrixXd rot(2,2);
	bool find = false;
	double deg,avg;
	deg = stringToNum<double>(s1);
	avg = deg*PI/180;
	rot(0,0)=cos(avg);
    rot(0,1)=sin(avg);
    rot(1,0)=-sin(avg);
    rot(1,1)=cos(avg);
   for(int i=0;i<PN;i++) {
		if(point[i].getName()==s) {
			find = true;
			Vector2d v1 = point[i].getPoint();
			 v1=rot*v1;
			 cout<<"点"<<s<<"绕原点旋转后的坐标为:"<<v1.transpose()<<endl;	
		} 
	}

	for(int i=0;i<LN;i++) {
		if(line[i].getName()==s) {
			find = true;
			Vector2d v1 = line[i].getStartPoint();
			Vector2d v2 = line[i].getEndPoint();
			 v1 = rot*v1;
			 v2 = rot*v2; 
			 cout<<"直线"<<s<<"旋转后起点的坐标为:"<<v1.transpose()<<endl;
			 cout<<"直线"<<s<<"旋转后终点的坐标为:"<<v2.transpose()<<endl;	
		} 
	}	
	
		for(int i=0;i<RN;i++) {
		if(rect[i].getName()==s) {
			find = true;
			Vector2d v1 = rect[i].getPoint1();
			Vector2d v2 = rect[i].getPoint2();
			Vector2d v3 = rect[i].getPoint3();
			 v1 = rot*v1;
			 v2 = rot*v2; 
			 v3 = rot*v3;
			 cout<<"三角形"<<s<<"点1旋转后的坐标为:"<<v1.transpose()<<endl;
			 cout<<"三角形"<<s<<"点2旋转后的坐标为:"<<v2.transpose()<<endl;
			 cout<<"三角形"<<s<<"点3旋转后的坐标为:"<<v2.transpose()<<endl;	
		} 
	}
	
	if(find==false) {
		cout<<"没有找到对应的点线面，请先添加点线面！"<<endl;
	} 
}






