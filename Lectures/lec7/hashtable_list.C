  //  This is a hash table experiment based on the newhashpjw

  #include <iostream>
  #include <string>
  #include "hash-list-functions.C"

  using namespace std;
//  const int PRIME = 211;

  class header { public :
                   int coll;
                   node * list;
  };

  void display (header * ht)
  { 
    // displays a htable 
    for ( int i = 0; i < PRIME ; i++ )
    {  if ( ht[i].coll != 0 )
       cout << " *************************************** " << endl
            << " No of elements at index " << i << " = " 
            <<  ht[i].coll << endl;
       node * p = ht[i].list;
       if ( p != 0 ) // traverse the nonempty list
       {
          cout << " The elements stored at index " << i << endl;
          display(p);
          cout << endl;
       };
    }
  }


  int main ()
  {
    int hashval;
    header htable[PRIME];

    // initialise the table ; each header entry 
    // will have two info - an integer field giving 
    //  number of collisions at this location
    // the other field is a pointer to a linked list.

    for ( int i = 0; i < PRIME ; i++ )
    {
       htable[i].coll = 0;
       htable[i].list = 0;
    };

    string name ;
    int count = 0;
    while ( cin >> name )
    { hashval = hashpjw(name);
      // check the list at index hashval in the table
      if (htable[hashval].list  == 0 ) // empty list, so insert
      {
        htable[hashval].list = new node;
        node * p = htable[hashval].list;
        p->val = name;
        p->next = 0; 
        htable[hashval].coll ++;
      }
      else  
      { // search in the list pointed to by p - 
        // if not present, then add at the last place         

        node * p = htable[hashval].list;
        if ( ! find(p, name))        
        {   append(htable[hashval].list, name);
            htable[hashval].coll ++;
        };
      }; 
      count ++;
    };

    cout << " ******* display of the hash table constructed ***** " 
	 << endl << endl;
    cout << " Total no. of symbols encoumtered = " << count << endl;
    display(htable);
  }
