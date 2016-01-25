      using namespace std;
      #include <iostream>
      
      const int SIZE = 100;

      float max ( float x, float y)
      { if ( x <= y ) return y;
        else return x;
      } 
      
      float max_pos_sum( float* b, int size, int low,
                         int high)
      { float maxsum = 0.0;
        if ( low > high) return maxsum;
        if ( low == high ) return maxsum = max (0.0, b[low]);
        int mid = (low + high)/2;
        
        float sum = 0.0, max2left = 0.0;
        for ( int i = mid; i >= low; i--)
        { sum = sum + b[i]; max2left = max (max2left, sum); };

        float max2right = 0.0;
        sum = 0.0;
        for ( int i = mid+1; i <= high; i++)
        { sum = sum + b[i]; max2right = max (max2right, sum); };
        
        float maxcrossing = max2left + max2right;
        float maxinA, maxinB;
        maxinA = max_pos_sum(b, size, low, mid);
        maxinB = max_pos_sum(b, size, mid+1, high);

        maxsum = max(maxinA, maxinB);
        return max(maxsum, maxcrossing); 
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
             << max_pos_sum(a, num, 0, num-1) << endl;
      }
