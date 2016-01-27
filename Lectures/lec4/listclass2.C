   // This design continues the evolution of a linked list class.
   // The improvements over listclass1.C include :
   // 1. use of operator+ in place of insert() 
   // 2. introduction of operator+ (overloaded) to take care of 
   // merging of two lists, and
   // 3. Replacing display() member function by an overloaded 
   // operator<<

    #include <iostream>
    #include <string>
    using namespace std;

    typedef string item_type;

    class list { 
        class node { public:
	     item_type val;
	     node * next;
             };
    public : node * head;
	    list() { head = 0;} // constructor
            
	    bool isempty ()
            { if ( head == 0 ) return true;
              else return false; }

  	    int length ()
            { node * p = head;
              int count = 0;
              while ( p != 0 ) { count ++; p = p->next; };
              return count;
            }

            list operator+ ( item_type elm )
            { node * p = new node;
            if ( p == 0 ) 
               cerr << " fatal error : no space on heap "
                    << endl;
               p->val = elm;
               p->next = head; // connects new node to list
               head = p;
               return (*this);
            }

            list operator+ ( list l)
            { 
            if ( head == 0 ) return l;
              else { 
                 node * curr = head; node * prev = head;
	         while ( curr != 0 ) {
		    prev = curr; curr = curr->next; };
                 prev->next = l.head;
              };
              return (*this);
             }
 
	    list append (item_type elm )
            { // find the last node of list
              node * p = new node;
              p->val = elm; p->next = 0;
              if ( head == 0 ) head = p;
              else { 
                 node * curr = head; node * prev = head;
	         while ( curr != 0 ) {
		    prev = curr; curr = curr->next; };
                 prev->next = p;
              };
              return (*this);
             }
            
	  void operator= ( node* p)
	    { head = p; return ;}
	    
	  friend ostream & operator<< (ostream &x, list l)
            { node * p = l.head;
              for ( int i = 1 ; i <= l.length(); i++ )
	      { x << " element no " << i << " is = " 
	       << p->val << endl; p = p->next;
              };
          return x;
          }
	  
    };

    int main()
    {   item_type num;
	list l,m ;
	while ( cin >> num) 
        { l = l.append(num);
          m = m + num;
        }
	cout << " length of list l = " << l.length() << endl;
	cout << " display of list l follows \n" << l << endl;
        cout << " length of list m = " << m.length() << endl;
	cout << " display of list m follows \n" << m << endl;
        cout << " display of merged list l + m \n" << l + m << endl;
    }
