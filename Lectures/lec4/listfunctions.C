// file that has all the non-member function definitions for
// class list 

   class node { public :
		  int val;
		  node * next;
   };

    // list of non-member functions
    // isempty(list) - returns true if list is empty false otherwise

   bool isempty (node * list)
   {
     if ( list == 0 ) return true;
     else return false;
   }

// length of a linked list
// length(list) - returns the number of elements in list

   int length (node * list)
   {
     node * p = list;
     int count = 0;
     while ( p != 0 )
       { count ++; p = p->next; };
     return count;
   }

// insert at the head of the list; a new element is inserted
// as the new first element of the list
// insert ( list, elm) : returns the address of a new list

   node * insert ( node * list, int elm )
   {
// add suitable code here 
     return list;
   }

// find an element in a given list
// find ( list, elm ) - returns the address of elm if found, 
// 0 otherwise

   node * find ( node * list, int elm )
   {
// add code here
     return list;
   }

// given a list and a value, delete the node containing the value 
// ( if on exists ) and return the new list; deletes the first 
// occurance only; for all deletions of the given element, a 
// different version needed

   node* del ( node * list, int elm )
   { 
      return list;
   }

// append function to insert an element at the end of a list

   node * append ( node * list, int elm )
   {
  // find the last node of list before adding the new element
     node * p = new node; // get 12 bytes from heap and save its address
     p->val = elm; // initialize its val part
     p->next = 0;  // initialize its next address part (end of list hence null) 
     if ( list == 0 ) list = p; // empty list is easy to handle
     else
        { node * curr = list; // address of the current list node
	  node * prev = list; // address of the previous list node
	  while ( curr != 0 )
	     { prev = curr;    // save address of curr node in prev 
	       curr = curr->next; // move curr to the next node
             };
          prev->next = p;      // prev holds the address of last node
        };                     // because it is the only node whose next is null
    return list;
   }

// a function to display a linked list

   void display (node * list)
   { node *p = list;
     for (int i = 1; i <= length(list); i++)
     { cout << " element no " << i << " is = " << p->val << endl;
       p = p->next;
     };
   }
