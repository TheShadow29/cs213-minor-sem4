#include <iostream>
using namespace std;

template <class T>

T sum1 (T arr[], int n)
{
	T sum = arr[0];
	for(int i = 1; i < n; i++)
	{
		sum += arr[i];
	}
	cout<<sum;
	return sum;
}

int main()
{
	int arr[] = {1,2,3,4};
	char b[] =  {'A','0'};
	cout<<sum1(arr,4)<<endl;
	cout<<sum1(b,2)<<endl;
}