#include <iostream>
using namespace std;

int main()
{
	union icfip
	{
		int i;
		char c;
		float x;
		bool p;
		int* q;
	};
	icfip data;
	cout<<"size of data"<<sizeof(data);
	//data has size = max of all of them
	int j = 50;
	data.i = j;
	cout<<"int "<<data.i<<endl;
	cout<<"char "<<data.c<<endl;
	cout<<"float "<<data.x<<endl;
	cout<<"bool "<<data.p<<endl;
	cout<<"int* "<<data.q<<endl;

}