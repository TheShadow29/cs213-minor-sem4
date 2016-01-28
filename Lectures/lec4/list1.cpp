#include <iostream>
#include <string>
using namespace std;

typedef string item_type;

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

		list insert(item_type elm)
		{
			node* p = new node;
			if (p==0)
			{
				cerr<<"no space in heap"<<endl;
			}
			p->val = elm;
			p->next = head;
			head = p;
			return (*this);
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

		void display()
		{
			node* p = head;
			for(int i = 0; p->next != 0; i++)
			{
				cout<<p->val<<" ";
				p = p->next;
			}
			cout<<p->val<<endl;
		}

};

int main()
{
	item_type num;
	list l, m;
	while(cin>>num)
	{
		l.insert(num);
		m.append(num);
	}
	cout<<"length of l: "<<l.length()<<endl;
	cout<<"l is: ";
	l.display();
	cout<<"length of m: "<<m.length()<<endl;
	cout<<"m is: "<<" "; 
	m.display();
}