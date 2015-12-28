#include <iostream>
#include <Eigen/Dense>
#include<math.h>
using Eigen::MatrixXd;
using namespace std;
int main()
{
    string Name,Action;
    int i,PointNumber;
    double MoveX,MoveY,RotateAngle;
    MatrixXd InputMatrix,OutputMatrix;
     
    cout<<"please input the information:";
    cin>>Name;
    cin>>PointNumber;
    InputMatrix.resize(PointNumber,2);
    OutputMatrix.resize(PointNumber,2);
	for (i=0;i<PointNumber;i++) //输入坐标 
	{ cin>>InputMatrix(i,0);
	  cin>>InputMatrix(i,1);
	}
	cin>>Action;
    if (Action=="move")   //   平移 
       { cin>>MoveX;
         cin>>MoveY;
         for (i=0;i<PointNumber;i++) 
		    { OutputMatrix(i,0)=InputMatrix(i,0)+MoveX;
	  		  OutputMatrix(i,1)=InputMatrix(i,1)+MoveY;
		    }
	   }
	else
		{ cin>>RotateAngle; //  旋转 
		  RotateAngle=RotateAngle*M_PI/180;
		  for (i=0;i<PointNumber;i++) 
		    { OutputMatrix(i,0)=InputMatrix(i,0)*cos(RotateAngle)-InputMatrix(i,1)*sin(RotateAngle);
	  		  OutputMatrix(i,1)=InputMatrix(i,1)*cos(RotateAngle)+InputMatrix(i,0)*sin(RotateAngle);
		    }
		}
	cout<<OutputMatrix;
}
