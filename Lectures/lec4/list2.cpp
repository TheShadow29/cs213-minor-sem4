#include <iostream>
#include <string>
using namespace std;

typedef int item_type;

class list
{
	class node
	{
		public:
			item_type val;
			node* next;	
	};
	public:
		node* head;
		list()
		{
			head=NULL;
		}

		bool isempty()
		{
			if (head==NULL)
			{
				return 1;
			}
			else{return 0;}
		}

		int length()
		{
			node* p = head;
			int count=0;
			while(p!=NULL)
			{
				p=p->next;
				count++;
			}
			return count;
		}

		list operator+ (item_type elm)
		{
			node* p = new node;
			if (p == 0)
			{
				cerr<<"No heap in memory"<<endl;
			}
			p->val = elm;
			p->next = head;
			head = p;
			return (*this);
		}

		list operator+ (list l)
		{
			if (head == 0) {return l;}
			else
			{
				node* curr = head;
				while(curr->next != 0)
				{
					curr = curr->next;
				}
				curr->next = l.head;
				return (*this);
			}
		}

		list append(item_type elm)
		{
			node* p =new node;
			p->val = elm;
			p->next = 0;
			
			if (head == 0)
			{
				head = p;
			}
			else
			{
				node* curr= head;
				while(curr->next!=NULL)
				{
					curr=curr->next;
				}
				curr->next = p;
			}
			return (*this);
		}

		void operator= (node* p)
		{
			head = p;
		}

		friend ostream & operator<< (ostream &x, list l)
		{
			node* p = l.head;
			int i;
			for(i = 0;p->next != 0; i++)
			{
				x << "index: "<<i<<" elm: " << p->val<<endl;
				p = p->next;
			}
			x << "index: "<<i+1<<" elm: " << p->val<<endl;
			//p = p->next;
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