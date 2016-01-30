#include <iostream>
#include "stack.hpp"
using namespace std;

template<class T>
stack<T>::stack()
{
	tos = NULL;
}

template<class T>
void stack<T>::push(T obj)
{
	node* to_push = new node;
	to_push->obj = obj;
	if (tos == NULL)
	{
		tos = to_push;
		to_push->next = NULL;
		return;
	}
	else
	{
		node* curr = this->tos;
		to_push->next = curr;
		this->tos = to_push;
		return;
	}
}

template<class T>
int stack<T>::top(T *top_element)
{
	if (tos == NULL)
	{
		return -1;
	}
	else
	{
		*top_element = tos->obj;
		return 1;
	}
}

template<class T>
void stack<T>::pop()
{
	if (tos==NULL)
	{
		return;
	}
	else
	{
		node* curr = tos;
		curr = curr->next;
		tos = curr;
		return;
	}
}

template<class T>
int stack<T>::size()
{
	if (tos == NULL)
	{
		return 0;
	}
	else
	{
		node* curr = tos;
		int i = 1;
		for(; curr->next != NULL; i++)
		{
			curr = curr->next;
		}
		return i;
	}
}

int main()
{
	 stack<int> s;
	 s.push(1);
	 s.push(2);
	int* a = new int; 
	*a = 10; 
	s.top(a);
	cout<<*a<<endl;
	s.push(3);
	s.push(4);
	s.pop();
	s.top(a);
	cout<<*a<<endl;
	cout<<s.size()<<endl;
	s.pop();
	s.pop();
	s.pop();
	s.pop();
	cout<<s.size()<<endl;
}