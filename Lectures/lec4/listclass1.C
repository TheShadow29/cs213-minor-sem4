    // In this class design,  linked list is a list of strings.  
    // The change needed to listclass0.C is minimal (use of typedef)
    // Just changing the typedef will make the program work for another 
    // type. This is C style reuse

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

            list insert ( item_type elm )
            { node * p = new node;
	      if ( p == 0 )
                 cerr << " fatal error : no space on heap "
                      << endl;
              p->val = elm;
              p->next = head; // connects new node to old list
              head = p;
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
	    
           void display ( )
            { node * p = head;
              for ( int i = 1 ; i <= this->length(); i++ )
	      { cout << " element no " << i << " is = " 
	       << p->val << endl; p = p->next;
              };
           }
    };

    int main()
    {   item_type num; // change
	list l,m ;
	while ( cin >> num) 
        { l = l.append(num);
          m = m.insert(num);
        }
	cout << " length of list l = " << l.length() << endl;
	l.display();
        cout << " length of list m = " << m.length() << endl;
        m.display();
    }
