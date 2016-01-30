#include <iostream>
#include "queue_vector.hpp"
using namespace std;

template<class T>
queue_vector<T>::queue_vector()
{
	fr = v.begin();
	rear = v.end();
}

template<class T>
void queue_vector<T>::push_back(T obj)
{
	v.push_back(obj);
	fr = v.begin();
	rear = v.end();
	return;
}

template<class T>
int queue_vector<T>::front(T *top_element)
{
	if (fr == v.end())
	{
		return -1;
	}
	else
	{
		*top_element = *fr;
		return 1;
	}
}

template<class T>
void queue_vector<T>::pop_front()
{
	if (fr == v.end())
	{
		return;
	}
	else
	{
		v.erase(fr);
		fr = v.begin();
		rear = v.end();
		return;
	}
}

template<class T>
int queue_vector<T>::size()
{
	return v.size();
}

int main()
{
	queue_vector<int> qv;
	qv.push_back(1);
	qv.push_back(2);
	int *a = new int;
	*a = 10;
	qv.front(a);
	cout<<*a<<endl;
	cout<<"size "<<qv.size()<<endl;
	qv.pop_front();
	qv.front(a);
	cout<<*a<<endl;
	cout<<"size "<<qv.size()<<endl;
	qv.pop_front();
	qv.front(a);
	cout<<*a<<endl;
	cout<<"size "<<qv.size()<<endl;
	qv.pop_front();
	qv.front(a);
	cout<<*a<<endl;
	cout<<"size "<<qv.size()<<endl;
}