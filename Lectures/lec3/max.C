#include <iostream>

using namespace std;

int max (int a[], int size)
{
  int res = a[0];
  for ( int i = 0; i < size; i++)
    if (a[i] > res) res = a[i];
  return res;
}

int main()
{ 
  int array[100], val, cnt=0; 
  while (cin >> val) {array[cnt] = val; cnt++;}
  cout << " Largest value in array[] is " << max(array, cnt) << endl; 
  return 0;
} 
