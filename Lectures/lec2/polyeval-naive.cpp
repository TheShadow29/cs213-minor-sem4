#include <iostream>
using namespace std;

float polyeval(float a[], int n, float val)
{
	float result, term;
	int i, j;
	result = a[0];
	for (i=0;i<n;i++)
	{
		term = val;
		for(j=0;j<i;j++){term*=val;}
		result += result + a[i]*term;
	}
	return result;
}

