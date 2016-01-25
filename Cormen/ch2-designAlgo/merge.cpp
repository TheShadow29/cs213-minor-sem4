#include <iostream>
#include <climits>
#include <fstream>
using namespace std;

void merge(int arr[],int p, int q, int r)
{
	//assumes arr[p to q] and arr[q+1 to r] is sorted
	//returns the merged A(p,q,r) in sorted order
	//ascending sorting
	int n1 = q-p+1;
	int n2 = r-q;
	int L[n1+1], R[n2+1];
	for(int i=0;i<n1;i++)
	{
		L[i]=arr[p+i];
	}
	L[n1]=INT_MAX;
	for(int i=0;i<n2;i++)
	{
		R[i]=arr[q+i+1];
	}
	R[n2]=INT_MAX;
	int i=0,j=0;
	for(int k=p;k<r+1;k++)
	{
		if(L[i]<R[j])
		{
			arr[k]=L[i];
			i++;
		}
		else
		{
			arr[k]=R[j];
			j++;
		}
	}
	return;
}

void merge_sort(int arr[], int p, int r)
{
	if (p==r){return;}
	int q=(p+r)/2;;
	if (p<r)
	{
		merge_sort(arr,p,q);
		merge_sort(arr,q+1,r);
		merge(arr,p,q,r);
	}
}

void print(int arr[],int p,int r, char k)
{
	if(k=='o')
	{
		ofstream ofile;
		ofile.open("out.txt");
		for (int i=p;i<r+1;i++)
		{
			ofile<<arr[i]<<' ';
		}
	}
	else if (k=='c')
	{
		for (int i=p;i<r+1;i++)
		{
			cout<<arr[i]<<' ';
		}		
	}
}

// void p2(int arr[], int n)
// {
// 	for(int i=0;i<n;i++)
// 	{
// 		arr[i]=0;
// 	}
// 	return;
// }

int main(int argc, char* argv[])
{	
	ifstream ifile;
	ifile.open("rand-array.txt");
	int x;
	int n;
	ifile>>n;
	cout<<n<<endl;
	int arr[n];
	for(int i=0;ifile>>x;i++)
	{
		arr[i]=x;
	}	
	ifile.close();
	merge_sort(arr,0,n-1);
	//p2(arr,n);
	print(arr,0,n-1,'o');
	//int foo[5]={1,2,3,6,5};
	//merge_sort(foo,0,4);
	//print(foo,0,4,'c');
}