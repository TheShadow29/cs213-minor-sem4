#include <iostream>
#include <fstream>

using namespace std;
const int SIZE = 110;
float max(float x, float y)
{
	if(x<=y){return y;}
	else{return x;}
}

float max_pos_sum(float b[], int n)
{
	float max_so_far = 0;
	float maxendinghere = 0;
	for (int i=0;i<n;i++)
	{
		maxendinghere += b[i];
		maxendinghere=max(maxendinghere,0);
		max_so_far=max(maxendinghere,max_so_far);
	}
	return max_so_far;
}
int main ()
{
	float a[SIZE];
	int num;
	ifstream in("max_sum_inp2",ios::in);
	ofstream out("output",ios::app);
	//coutof << " give the number of elements ";
	in >> num; //out << endl<< " give elements " ;
	for ( int i = 0; i < num; i++ ) in >> a[i]; out << endl;
	out << " max +ve sum in array a[] = " << max_pos_sum(a, num) << endl;
}