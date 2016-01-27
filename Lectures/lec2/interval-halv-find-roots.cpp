#include <iostream>
#include <stdlib.h>
using namespace std;
const int SIZE = 110;

float horner(float a[], int n, float val)
{
	float result;
	int i;
	result = a[n];
	for (i=n;i>0;i--)
	{
		result = val * result + a[i-1];
	}
	return result;
}
float halving(float coeff[], int degree, float a, float b)
{
	float fa, fb, fmid, mid;
	while(abs(abs(a) - abs(b))>0.001)
	{
		fa = horner(coeff,degree,a);
		fb = horner(coeff,degree,b);

		if (fa*fb > 0)
		{
			cerr<<"error interval";
		} 
		mid = (a+b)/2.0;
		fmid = horner(coeff,degree,mid);

		if(fmid * fa < 0)
		{
			b = mid;
		}
		else
		{
			a = mid;
		}
	}
	return mid;
}
int main()
{
	float a[4] = {6,11,6,1};
	float b[4] = {8,0,0,1};
	cout<<halving(a,3,10,-5.5)<<endl;
}