using namespace std;
      #include <iostream>
      
      const int SIZE = 110;

      float max ( float x, float y)
      { if ( x <= y ) return y;
        else return x;
      } 

      float max_pos_sum( float* b, int size)
      {
        float maxsofar = 0.0;
        for (int i = 0; i < size; i++)
          for ( int j = i; j < size; j++)
            { float sum = 0.0;
              for ( int k = i; k <=j; k++)
                 sum = sum + b[k];
              maxsofar = max(maxsofar, sum);
            };
        return maxsofar;
      }
 
      int main()
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
