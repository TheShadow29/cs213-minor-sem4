      #include <iostream>
      using namespace std;
      int main()
      {
         union test {
            int i;
            char c;
            float x;
            int* p;
         };  // defines a union 
         int j;
         test data;  
         // declares an object data of type test
         cout << " size of union " << sizeof(data) 
              << endl;
         cout << " give an integer : " ;
         cin >> j ;
         cout << " input value is : " << j << endl;
         data.i = j;
         cout << " interpreted as integer : " 
              <<  data.i << endl;
         cout << " interpreted as character : " 
              << data.c << endl;
         cout << " interpreted as float : " 
              << data.x << endl;
         cout << " interpreted as pointer : " 
              << data.p << endl;
     }
