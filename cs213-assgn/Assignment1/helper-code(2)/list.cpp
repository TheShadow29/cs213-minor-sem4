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
