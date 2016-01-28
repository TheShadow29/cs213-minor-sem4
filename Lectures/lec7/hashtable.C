//  This is a hash table experiment based on the hashpjw
// function used earlier 
// hash table experiment based on the hashpjw

   #include <iostream>
   #include <string>
   using namespace std;
   const int PRIME = 211;

   int hashpjw(string s)
   {
     char p;
     unsigned h =0, g;
     for ( int i = 0; i < s.length() ; i++ )
     {  
       h = ( h << 4 ) + ( s[i] );
       if ( g = h&0xf0000000 )
       { 
         h = h ^ ( g << 24 );
         h = h ^ g;
       }
     }
     return h % PRIME;
   }

   class node { public :
        string key;
        node * next ;
   };
   class header { public :
        int coll;
        node * list;
   };

   void display (header * ht)
   { 
     // displays a htable 
     for ( int i = 0; i < PRIME ; i++ )
     {  if ( ht[i].coll != 0 )
        cout << " No of elements at index " << i 
             << " = " << ht[i].coll << endl;
        node * p = ht[i].list;
        if ( p != 0 ) // traverse the nonempty list
        {
          node *front = p->next; 
          cout << " The elements stored at index " 
               << i << " are : \n";
          while ( front != p ) 
          { cout << front->key << "  "; 
            front = front->next;
          };
          cout << p->key << "  ";  // now display the rear
          cout << endl;
        };
     }
   }
   int main ()
   {
     int hashval;
     header htable[PRIME];

    // initialise the table ; each header entry will have two info -
    // an integer field giving number of collisions at this location
    // the other field is a pointer to a linked list.

    for ( int i = 0; i < PRIME ; i++ )
    {
       htable[i].coll = 0;
       htable[i].list = 0;
    };

    string name ;
    int count = 0;
    while ( cin >> name )
    { 
      // search if the key "name" is present in htable.
      // get the index after hashing

      hashval = hashpjw(name);

      // check the list at index hashval in the table
             
      if (htable[hashval].list  == 0 ) // empty list, so insert
      {
         htable[hashval].list = new node;
         node * p = htable[hashval].list;
         p->key = name;
         p->next = p; // singleton circular list;
         htable[hashval].coll ++;
      }
      else  {
        // search in the list pointed to by p - note that
        // it is a circular list and is desired to be kept
        // as a queue; p points to the rear.

         node * p = htable[hashval].list;
         node * front = p->next;
         bool found = front->key == name || front == p;
         while ( ! found ){
             front = front->next;
             found = front->key == name || front == p;
         };
         if ( front->key == name ) ; // cout << " found in list \n";
         // searched key is present in table if tmp->key == name
         // must insert in list pointed by p after p;
         else  {
              node *q = new node;
              node *t = p->next;
              p->next = q;
              q->key = name;
              q->next = t;
              htable[hashval].list = q;
              htable[hashval].coll ++;
         };
        }; count ++;
      };

      cout << " ******* display of the hash table constructed ***** " 
	 << endl << endl;
      cout << " Total no. of symbols = " << count << endl;
      display(htable);
   }
