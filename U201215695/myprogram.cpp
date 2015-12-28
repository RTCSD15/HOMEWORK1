#include<iostream>
#include<Eigen/Dense>
#include<math.h>
using Eigen::MatrixXd;
using namespace std;

int main() 
{
	string Name,Action;
	int PointNumber,ActionNumber;
	double PointOneX,PointOneY,PointTwoX,PointTwoY,PointThreeX,PointThreeY,MoveX=0,MoveY=0,RotateAngle=0;
	MatrixXd TotateMatrix(2,2),FinalMatrix;
	MatrixXd InputMatrix1(1,2),InputMatrix2(2,2),InputMatrix3(3,2),MoveMatrix1(1,2),MoveMatrix2(2,2),MoveMatrix3(3,2);
	
	cout<<"please input the information:";
	cin>>Name;
	cin>>PointNumber;
	switch(PointNumber)      //确定输入点构成的矩阵； 
		{
			case 1: cin>>PointOneX;cin>>PointOneY;
				    InputMatrix1<<PointOneX,PointOneY;break;
				    
			case 2:	cin>>PointOneX;cin>>PointOneY;cin>>PointTwoX;cin>>PointTwoY;
			        InputMatrix2<<PointOneX,PointOneY,
			                     PointTwoX,PointTwoY;break;
			        
			case 3: cin>>PointOneX;cin>>PointOneY;cin>>PointTwoX;cin>>PointTwoY;cin>>PointThreeX;cin>>PointThreeY;
			        InputMatrix3<<PointOneX,PointOneY,
			                      PointTwoX,PointTwoY,
			                      PointThreeX,PointThreeY;break;
			       
		    default: cout<<"error";return 0;
		}
	
	cin>>Action;
	if(Action=="move") {ActionNumber=7;cin>>MoveX;cin>>MoveY;}
   	else {ActionNumber=11;cin>>RotateAngle;}
	RotateAngle=RotateAngle*M_PI/180;
	
	switch(ActionNumber*PointNumber)     //实现平移或旋转运动； 
		{
			case 11:TotateMatrix<<cos(RotateAngle),sin(RotateAngle),
			        -sin(RotateAngle),cos(RotateAngle);
			        cout<<InputMatrix1*TotateMatrix;break;
			        
			case 22:TotateMatrix<<cos(RotateAngle),sin(RotateAngle),
			        -sin(RotateAngle),cos(RotateAngle);
			        cout<<InputMatrix2*TotateMatrix;break;
			        
			case 33:TotateMatrix<<cos(RotateAngle),sin(RotateAngle),
			        -sin(RotateAngle),cos(RotateAngle);
			        cout<<InputMatrix3*TotateMatrix;break;
			        
			case 7:MoveMatrix1<<MoveX,MoveY;
			      cout<<InputMatrix1+MoveMatrix1;break;
			      
			case 14:MoveMatrix2<<MoveX,MoveY,
			                      MoveX,MoveY;
			        cout<<InputMatrix2+MoveMatrix2;break;
			        
			case 21:MoveMatrix3<<MoveX,MoveY,
			                      MoveX,MoveY,
			                      MoveX,MoveY;
			        cout<<InputMatrix3+MoveMatrix3;break;
		}
	
	return 0;
}
