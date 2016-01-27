#include <iostream>

using namespace std;

template <class T>

T max(T arr[], int n)
{
	T res = arr[0];
	for (int i = 0; i < n;i++)
	{
		if (arr[i] > res)
		{
			res = arr[i];
		}
	}
	return res;
}

int main()
{
	int arr[5] = {4,2,12,53,-1};
	char brr[5] = {'c','1','a','Z','z'};
	//cout<<max(brr,5)<<endl;
	int* ptr = new int;
	cout<<sizeof(int*);
}