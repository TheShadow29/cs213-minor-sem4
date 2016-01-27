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
  string str[] = {"C", "PYTHON", "CUDA", "JAVA"};
  int a[] ={ 3, -5, 50, 20, 1};
  char ch[] ={ 'a', ';', '$', 'Z', '#'};
  cout << " Largest value iis " << max(str, 4) << endl; 
  cout << " Largest value iis " << max(ch, 5) << endl; 
  cout << " Largest value iis " << max(a, 5) << endl; 
  return 0;
} 
