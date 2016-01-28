//  This is a C++ equivalent of the hashpjw program usually
//  written in c and commonly used by compiler writers

  #include <iostream>
  #include <string>

  using namespace std;
  const int  PRIME = 211;

  int hashpjw(string s)
  {
    char p;
    unsigned h =0, g;
    cout << sizeof h << endl;
    for ( int i = 0; i < s.length() ; i++ )
    {  
      cout<<"line 17 "<<h<<endl;
      h = ( h << 4 ) + ( s[i] );
      cout << " s[i] : " << s[i] << " h = " << h << endl;  
      cout << " h & 0xf0000000 : " << (h&0xf0000000) << endl;   
      if ( g = h&0xf0000000 )
      { 
        cout << " g = " << g << " h = " << h << endl;     
        h = h ^ ( g << 24 );
        h = h ^ g;
        cout << " g = " << g << " h = " << h << endl;     
      }
    }
    return h % PRIME;
   }

   int main ()

    {
      int hashval;
      string name ="arka";
      
       hashval = hashpjw(name);
        cout << " symbol is " << "'" 
	 << name << "'" << "      hash value is  " 
	 << hashval << endl;
      
   }
