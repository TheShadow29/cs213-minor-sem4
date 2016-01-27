#include <iostream>
using namespace std;

float polyeval(float a[], int n, float val)
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

int main()
{
	float a[4] = {1,1,2,1};
	cout<<polyeval(a,3,2)<<endl;
}

