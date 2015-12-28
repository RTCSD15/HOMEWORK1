#include <iostream>
#include <Eigen/Dense>
#include <math.h>
using namespace std;
using namespace Eigen;
// 图形类 
class graph{
private:
	string name;
	int pointNumber;            //存坐标对数 
    Vector2d coordinate[3];     //向量数组，存坐标 
public:
	//构造函数 
	graph(){
	}
	graph(string na,int poi){
		name=na;
		pointNumber=poi;
	}                           
	void setName(string na){
	name=na;
	}
	void setPoint(int p){
	pointNumber=p;
	}
	void setpCoordinate(double x1,double y1){
		
		coordinate[0][0]=x1;
		coordinate[0][1]=y1;
	}                            //点坐标赋值 
	void setlCoordinate(double x1,double y1,double x2,double y2){
		coordinate[0][0]=x1;
		coordinate[0][1]=y1;
		coordinate[1][0]=x2;
		coordinate[1][1]=y2;
	}                           //线坐标赋值 
	void settCoordinate(double x1,double y1,double x2,double y2,double x3,double y3){
		coordinate[0][0]=x1;
		coordinate[0][1]=y1;
		coordinate[1][0]=x2;
		coordinate[1][1]=y2;
		coordinate[2][0]=x3;
		coordinate[2][1]=y3;
	}                            //三角形坐标赋值 
	string getName(){
		return name;
	}
	int getPoint(){
		return pointNumber;
	}
	
	RowVector2d* getCoordinate(){
		RowVector2d *vv =new RowVector2d[pointNumber];//指向向量数组的指针，获取数组地址 
		for(int i=0;i<pointNumber;i++){
			vv[i]=coordinate[i];
		}
		return vv;
	}
	//输出显示函数 
	void show(){                                  
		if(pointNumber==1){
		   cout<<"name:"<<getName()<<endl<<"point number:"<<getPoint()<<endl;
		   cout<<"coordinates:"<<"("<<getCoordinate()[0]<<")"<<endl;
	} 
	else if(pointNumber==2){
		cout<<"name:"<<getName()<<endl<<"point number:"<<getPoint()<<endl;
		cout<<"coordinates:"<<"("<<getCoordinate()[0]<<")"<<"("<<getCoordinate()[1]<<")"<<endl;
	}
	else if(pointNumber==3){
		cout<<"name:"<<getName()<<endl<<"point number:"<<getPoint()<<endl;
		cout<<"coordinates:"<<"("<<getCoordinate()[0]<<")"<<"("<<getCoordinate()[1]<<")"<<"("<<getCoordinate()[2]<<")"<<endl;
	}
  }
};
//操作类 
class operate{
	private:
		graph Gr;
		string order;          //获取命令 
	public:
        void setgraph(graph gr){
        	Gr=gr;
		}
		void setOrder(string ord){
		order=ord;
		}
		string getOrder(){
			return order;
		}
	// 显示命令后坐标变换 
		void show(){
			if (order=="move")
			cout<<"after moved the coordinates are:"<<endl;
			else if(order=="rotate")
			cout<<"after rotated the coordinates are:"<<endl;
			else cout<<"the wrong order!"<<endl;
		    
			if(Gr.getPoint()==1){
		   cout<<"coordinates:"<<"("<<Gr.getCoordinate()[0]<<")"<<endl;
	                       } 
         else if(Gr.getPoint()==2){
		    cout<<"coordinates:"<<"("<<Gr.getCoordinate()[0]<<")"<<"("<<Gr.getCoordinate()[1]<<")"<<endl;
	                }
	    else if(Gr.getPoint()==3){
		cout<<"coordinates:"<<"("<<Gr.getCoordinate()[0]<<")"<<"("<<Gr.getCoordinate()[1]<<")"<<"("<<Gr.getCoordinate()[2]<<")"<<endl;
	  }
		}
	//移动函数 
	    void move(double x,double y){
	    	double x1,y1,x2,y2,x3,y3;
			RowVector2d xy;    //用向量获取参数，实现向量相加 
			RowVector2d xxy;   //暂时存储变换后坐标 
	    	xy[0]=x;
	    	xy[1]=y;  //用向量存储移动参数 
	    	RowVector2d *vv=Gr.getCoordinate();//得到图像的坐标数组 
	    	if(Gr.getPoint()==1){
	    		xxy=xy+vv[0];
	    		x1=xxy[0];
	    		y1=xxy[1];
	    		Gr.setpCoordinate(x1,y1);
			}
	    else if(Gr.getPoint()==2){
	    	   xxy=xy+vv[0];
	    		x1=xxy[0];
	    		y1=xxy[1];
	    		xxy=xy+vv[1];
	    		x2=xxy[0];
	    		y2=xxy[1];
	    		Gr.setlCoordinate(x1,y1,x2,y2);
		}
		else if(Gr.getPoint()==3){
	    	   xxy=xy+vv[0];
	    		x1=xxy[0];
	    		y1=xxy[1];
	    		xxy=xy+vv[1];
	    		x2=xxy[0];
	    		y2=xxy[1];
	    		xxy=xy+vv[2];
	    		x3=xxy[0];
	    		y3=xxy[1];
	    		Gr.settCoordinate(x1,y1,x2,y2,x3,y3);
		}
		}
	
	//旋转函数 
		void rotate(double deg){
			double x1,y1,x2,y2,x3,y3;
	    	RowVector2d *vv=Gr.getCoordinate();//得到图像的坐标数组 
	    	if(Gr.getPoint()==1){
	    		x1=vv[0][0]*cos(3.14*deg/180)-vv[0][1]*sin(3.14*deg/180);
	    		y1=vv[0][0]*sin(3.14*deg/180)+vv[0][1]*cos(3.14*deg/180);
	    		Gr.setpCoordinate(x1,y1);
			}
		   else if(Gr.getPoint()==2){
	    		x1=vv[0][0]*cos(3.14*deg/180)-vv[0][1]*sin(3.14*deg/180);
	    		y1=vv[0][0]*sin(3.14*deg/180)+vv[0][1]*cos(3.14*deg/180);
	    		x2=vv[1][0]*cos(3.14*deg/180)-vv[1][1]*sin(3.14*deg/180);
	    		y2=vv[1][0]*sin(3.14*deg/180)+vv[1][1]*cos(3.14*deg/180);
	    		Gr.setlCoordinate(x1,y1,x2,y2);
			}
			else if(Gr.getPoint()==3){
	    		x1=vv[0][0]*cos(3.14*deg/180)-vv[0][1]*sin(3.14*deg/180);
	    		y1=vv[0][0]*sin(3.14*deg/180)+vv[0][1]*cos(3.14*deg/180);
	    		x2=vv[1][0]*cos(3.14*deg/180)-vv[1][1]*sin(3.14*deg/180);
	    		y2=vv[1][0]*sin(3.14*deg/180)+vv[1][1]*cos(3.14*deg/180);
	    		x3=vv[2][0]*cos(3.14*deg/180)-vv[2][1]*sin(3.14*deg/180);
	    		y3=vv[2][0]*sin(3.14*deg/180)+vv[2][1]*cos(3.14*deg/180);
	    		Gr.settCoordinate(x1,y1,x2,y2,x3,y3);
			}
		} 
};

int main(){
	graph g1;          //图形对象 
	operate op;        //操作对象 
	string Name;       //图形名称 
	string order;      //操作命令名称 
	int PointNum;
	double deg;
	double x1,y1,x2,y2,x3,y3,mov1,mov2;
	
	/////////获取输入的图形对象 
		cout<<"input the name,point number and the coordinates of each point:"<<endl; 
		cin>>Name>>PointNum;
	  g1.setName(Name);
	  g1.setPoint(PointNum);
		if(PointNum==1){
			cin>>x1>>y1;
			g1.setpCoordinate(x1,y1);
			g1.show();

		}
		if(PointNum==2){
			cin>>x1>>y1>>x2>>y2;
			g1.setlCoordinate(x1,y1,x2,y2);
			g1.show();
		}
		if(PointNum==3){
			cin>>x1>>y1>>x2>>y2>>x3>>y3;
			g1.settCoordinate(x1,y1,x2,y2,x3,y3);
			g1.show();			
		}
   ////////// 根据输入的命令对获取的图形对象操作，并输出操作后结果 
	cout<<"input the order:"<<endl;
	cin>>order;
				if(order=="move"){
					cin>> mov1>>mov2;
					op.setgraph(g1);
					op.setOrder(order);
					op.move(mov1,mov2);
					op.show();	
				}
			 else if(order=="rotate"){
					cin>> deg;
					op.setgraph(g1);
					op.setOrder(order);
					op.rotate(deg);
					op.show();
				}
			 else cout<<"the wrong order!"<<endl;
 	 return 0;
}
