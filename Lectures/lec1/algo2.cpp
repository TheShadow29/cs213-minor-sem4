#include <iostream>
using namespace std;
const int SIZE = 110;
float max(float x, float y)
{
	if(x<=y){return y;}
	else{return x;}
}

float max_pos_sum(float arr[], int n)
{
	float max_so_far=0;
	for(int i=0;i<n;i++)
	{
		float sum=0;
		for(int j=i;j<n;j++)
		{
			sum+=arr[j];
			max_so_far=max(max_so_far,sum);
		}
	}
	return max_so_far;
}
int main ()
{
    float a[SIZE];
    int num;
    cout << " give the number of elements ";
    cin >> num; cout << endl<< " give elements " ;
    for ( int i = 0; i < num; i++ )
        cin >> a[i]; cout << endl;
    cout << " max +ve sum in array a[] = "
         << max_pos_sum(a, num) << endl;
}