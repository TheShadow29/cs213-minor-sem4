#include <iostream>
#include <stdlib>
using namespace std;

void derivpoly(float p[], float dp[], int &deg)
{
	for (int i=0;i<deg;i++)
	{
		dp[i] = p[i+1]*(i+1);		//6
		//cout<<dp[i]<<endl;
	}
	deg--;		//2
	return;

	//6*deg + 2 +10
}

float horner(float a[], int n, float val)
{
	float result;			
	int i;
	result = a[n];		//2
	for (i=n;i>0;i--)
	{
		result = val * result + a[i-1];			//5
	}
	return result;				
	//cost = 5*n + 2 + 10
}

void reduced_poly(float coeff[], float root, int &deg)
{
	if (deg == 1)
	{
		coeff[0] = coeff[1];
		coeff[1] = 0;
		deg--;
		return;
	}

	float p[deg];
	p[deg]=0;			//2
	int i = deg-1;		
	p[i] = coeff[deg];	//4
	i--;
	for (;i>=0; i--)
	{
		p[i] = coeff[i+1] + root * p[i+1];	//8
	}
	for (int j=0;j<=deg-1;j++)
	{
		coeff[j]=p[j];						//3		
		//cout<<coeff[j]<<"x^"<<j<<" ";
	}
	cout<<endl;
	deg--;			//1
	return;
	//cost : 11*deg + 2+ 4+ 1 = 11*deg +7
}

float newton_raphson(float coeff[], int degree, float x0)
{
	float newroot, oldroot, fx0, dfx0; //4 floats
	float deriv[degree];	//float[]
	int count = 0;			//1
	newroot = x0;			//1

	do
	{
		oldroot = newroot; 								//1
		fx0 = horner(coeff, degree+1, oldroot);			//degree
		derivpoly(coeff, deriv, degree);				//degree
		dfx0 = horner(coeff,degree+1,oldroot);			//degree-1
		newroot  = oldroot - fx0/dfx0;					//3
	}while(abs(newroot - oldroot) > 0.0001)				

	return newroot;
}

int main()
{
	int deg = 2;
	float arr[] = {1,2,1};
	//float dp[deg-1];
	//derivpoly(arr,dp,deg);
	//cout<<deg;
	//cout<<polyeval(dp,deg+1,3);
	reduced_poly(arr,-1,deg);
}