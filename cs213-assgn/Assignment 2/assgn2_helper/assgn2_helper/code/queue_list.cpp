#include <iostream>
#include "queue_list.hpp"

using namespace std;

template<class T>
queue_list<T>::queue_list()
{
	num = 0;
	fr = q.end();
	rear = q.end();
}

template<class T>
void queue_list<T>::push_back(T obj)
{
	q.push_back(obj);
	fr = q.begin();
	rear = q.end();	
	num++;
	return;
}

template<class T>
int queue_list<T>::front(T *top_element)
{
	if (fr == q.end())
	{
		//cout<<"line 27"<<endl;
		return -1;
	}
	else
	{
		*top_element = *fr;
		return 1;
	}
}

template<class T>
void queue_list<T>::pop_front()
{
	if (fr == q.end())
	{
		return;
	}
	else
	{
		q.pop_front();
		fr = q.begin();
		rear = q.end();
		num--;
	}
}


template<class T>
int queue_list<T>::size()
{
	return num;
}

int main()
{
	queue_list<int> q1;
	q1.push_back(2);																																				
	q1.push_back(3);
	int *a = new int;
	q1.front(a);
	cout<<*a<<endl;
	cout<<"size: "<<q1.size()<<endl;
	q1.pop_front();																																																			
	q1.front(a);
	cout<<*a<<endl;
	cout<<"size: "<<q1.size()<<endl;
	q1.pop_front();
	q1.front(a);
	cout<<*a<<endl;
	cout<<"size: "<<q1.size()<<endl;
	q1.pop_front();
	cout<<"size: "<<q1.size()<<endl;
}