#include "node.hpp"
#include "node.cpp"
#include "list.hpp"
#include <iostream>
using namespace std;
Node* insert(Node* head, int val, int pos)
{
	if (head==NULL)
	{
		Node* ins=new Node(val);
		ins->setNext(NULL);
		return ins;
	}
	if (pos==0)
	{
		Node* ins=new Node(val);
		ins->setNext(head);
		return ins;
	}
	Node* next = head;
	while (pos>1)
	{
		next = next->getNext();
		pos--;
	}
	Node* ins = new Node(val);
	ins->setNext(next->getNext());
	next->setNext(ins);
	return head;
}

Node* remove(Node* head, int pos)
{
	if (head==NULL)
	{
		return head;
	}
	Node* next=head;
	if (pos==0)
	{
		next=next->getNext();
		return next;
	}
	
	Node* prev=head;

	for(int i=0;i<pos;i++)
	{
		prev=next;
		next=next->getNext();
	}
	prev->setNext(next->getNext());
	next=NULL;
	return head;

}

int size(Node* head)
{
	if (head==NULL)
	{
		return 0;
	}
	Node* next=head;
	int i=0;
	while(next->getNext()!=NULL)
	{
		next=next->getNext();
		i++;
	}
	return ++i;
}

Node* reverse(Node* head)
{
	if (head==NULL){return head;}
	Node* next=head;
	Node* x1=new Node(head->getVal());
	x1->setNext(NULL);
	while(next->getNext()!=NULL)
	{
		next=next->getNext();
		x1=insert(x1,next->getVal(),0);
	}
	return x1;
}

void disp(Node *head)
{
	if (head==NULL)
	{
		return;
	}
	while(head->getNext() != NULL)
	{
		std::cout << head->getVal() << '\n';
		head = head->getNext();
	}
	std::cout << head->getVal() << '\n';
}

int cycle_size(Node* head)
{
	if (head==NULL){return 0;}
	Node* fast=head;
	Node* slow=head;
	bool guess=0;
	while(fast->getNext()!=NULL && (fast->getNext())->getNext()!=NULL)
	{
		fast=fast->getNext();
		fast=fast->getNext();
		slow=slow->getNext();
		if (fast==slow)
		{
			slow=head;
			guess=1;
			break;
		}
	}
	if (guess==1)
	{
		while(fast->getNext()!=NULL)
		{
			fast=fast->getNext();
			slow=slow->getNext();
			if (fast==slow)
			{
				fast=fast->getNext();
				break;
			}	
		}
		int j=1;
		while(fast!=slow)
		{
			fast=fast->getNext();
			j++;
		}
		return j;
	}
	else
	{
		return 0;
	}
}

int main()
{
	int a = 1, b = 2, c = 3, d = 4, e = 5;
	Node a1(a), b1(b), c1(c), d1(d), e1(e);
	a1.setNext(&b1);
	b1.setNext(&c1);
	c1.setNext(&d1);
	d1.setNext(&e1);
	//e1.setNext(&a1);
	//cout<<size(&a1)<<endl;
	//disp(&a1);
	//Node* a2 = insert(&a1, 7, 0);
	//Node* x1=remove(&a1,0);
	//disp(x1);
	//disp(a2);
	Node* b2=insert(NULL,1,0);
	//Node* x2=insert(b2,5,0);
	//cout<<size(x2)<<endl;
	Node* q=remove(b2,0);
	//disp(q);
	//Node* r1=reverse(&a1);
	//Node* r2=reverse(b2);
	//disp(r2);
	cout<<cycle_size(q)<<endl;
}