#include <iostream>
#include <string>
using namespace std;

template <class T>
T max (T a[], int size)
{
  T res = a[0];
  for ( int i = 0; i < size; i++)
    if (a[i] > res) res = a[i];
  return res;
}

int main()
{ 
  int num;
  string array[100];
  cout << " Give number of elements :" ; cin >> num;
  for ( int i = 0; i < num; i++) cin >> array[i];
  cout << " Largest value in array[] is " << max(array, num) << endl; 
  int b[100];
  for ( int i = 0; i < num; i++) cin >> b[i];
  cout << " Largest value in array[] is " << max(b, num) << endl; 
  return 0;
} 
