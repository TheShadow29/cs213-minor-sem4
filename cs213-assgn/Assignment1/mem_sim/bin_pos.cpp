#include <iostream>
using namespace std;

int bin_pos(int arr[], int n, int val)
{
	if (n==0){return 0;}
	int mid, lb=0, ub=n-1;
	while(lb<=ub)
	{
		mid=(lb+ub)/2;
		if(val>arr[mid]){lb=mid+1;}
		else if(val<arr[mid]){ub=mid-1;}
		else{return mid;}
	}
	if(val>arr[mid]){return mid+1;}
	else{return mid;}
}
int main()
{
	int foo[5]={2,16,40,77,120};
	int k=bin_pos(foo,5,80);
	cout<<k<<endl;
}