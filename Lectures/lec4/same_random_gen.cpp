#include <iostream>
#include <fstream>
#include <stdlib.h> //required for rand() library function

using namespace std;

int main()
{
	ofstream out("random",ios::out);
	int num; cin >> num;
	int low, high, range;
	cin >> low >> high;
	out << num << endl;
	range = high - low + 1; 
	if (low < 0){low = -low;}
	for (int i =0; i<num; i++)
	{
		out << (rand() % range) - low << ' '; 
	}
	out<<endl;
}
