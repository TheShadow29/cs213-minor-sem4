#include <iostream>
using namespace std;

void reduced_poly(int &deg, float coeff[], float root)
{
	float p[deg];
	if (root != 0)
	{
		p[0] = -coeff[0]/root;

		for(int i = 0; i < deg; i++)
		{
			p[i] = (p[i-1] - coeff[i]) / root;
		}
		for (int i = 0; i < deg; i++)
		{
			coeff[i] = p[i];
		}
	}
	else
	{
		for (int i = 0; i < deg; i++)
		{
			coeff[i] = coeff[i+1];
		}
	}
	deg--;
	return;
}


int main()
{
	int deg = 2;
	float arr[] = {0,2,1};
	reduced_poly(deg,arr,0);
	for (int i = 0; i <= deg; i++)
	{
		cout << arr[i] <<endl;
	}
}