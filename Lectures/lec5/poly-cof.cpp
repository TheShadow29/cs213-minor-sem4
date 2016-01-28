#include <iostream>
using namespace std;

void disp(float arr[], int size)
{
	for(int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void poly_coeff (float root, int new_degree, float* b)
{
	//will compute (x-r)*b
	//cout<<"root: "<<root<<endl;
	if (new_degree==1)
	{
		b[1]=1;
		b[0]=-root;
		return;
	}
	b[new_degree]=b[new_degree-1];
	for(int i = new_degree-1;i>0;i--)
	{
		b[i] = b[i-1] - root*b[i];
	}
	cout<<b[0]<<endl;
	b[0] = -root*b[0];
	//cout<<b[0]<<endl<<endl;
	//disp(b,new_degree);
	return;
}

int main()
{
	int degree = 3;
	int d = degree;
	float roots[] = {1.0,4.0,5.0};
	float coeff[degree + 1];
	for (int i = 0; i < degree; i++)
	{
		poly_coeff(roots[i], i+1, coeff);
		//cout<<coeff[0];
	}
	disp(coeff,degree+1);

}