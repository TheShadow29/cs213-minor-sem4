  #include <iostream>
  #include <string>

  const int PRIME = 211;

  using namespace std;
  //  file for working with a linked list

  class node { public :
		 string val;
		 node * next;
  };

  // list of functions
  // isempty(list) - returns rtue if list is empty false otherwise

  bool isempty ( node * list )
  {
   if ( list == 0 ) return true;
   else return false;
  }

  // length of a linked list
  // length(list) - returns the number of elements in list

  int length ( node * list )
  {
    node * p = list;
    int count = 0;
    while ( p != 0 )
    { count ++; p = p->next; };
    return count;
  }

  bool  find ( node * list, string elm )
  {
    node *p = list;
    bool found = false;
    while ( p != 0 )
    {    // not found, so move to next node
       if ( p->val == elm ) 
            { found = true; break;};
        p = p->next;
    };
    return (found);
  }

  // append function to insert an element at the end of a list

  node * append ( node * list, string elm )
  {
    // find the last node of list
    // empty list is easy to handle
    node * p = new node;
    p->val = elm;
    p->next = 0;
    if ( list == 0 ) list = p;
    else
    {  node * curr = list;
       node * prev = list;
       while ( curr != 0 )
      {   prev = curr;
          curr = curr->next;
      };
      prev->next = p;
    };
    return list;
  }

  // a function to display a linked list

  void display ( node * list )
  { node * p = list;
    for ( int i = 1 ; i <= length (list) ; i++ )
    { cout << " element no " << i << " is = " << p->val
           << endl;
      p = p->next;
    };
  }

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

