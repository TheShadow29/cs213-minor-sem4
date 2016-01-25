#include <iostream>
#include <fstream>
#include <list>
using namespace std;

class Ref
{
public:
	int freq,val;
	Ref(int value)
	{
		freq=0;
		val=value;
	}
	void inc_freq(){freq++;}
	int getval(){return val;}
	int getfreq(){return freq;}
};

int main()
{
	list<Ref> mem_perm;
	list<Ref> temp;
	Ref k1=Ref(0);temp.push_back(k1);
	int max_id;cin>>max_id;
	int frames;cin>>frames;
	int pages;cin>>pages;
	int hit=0,miss=0;
	if(frames>=pages)
	{
		cout<<pages<<endl;
		cout<<"0"<<endl;
		return 0;
	}

	int x;
	list<Ref>::iterator arr[max_id];
	for(int i=0;i<max_id;i++){arr[i]=temp.end();}
	int mem_perm_size=0;
	cin>>x;
	miss++;
	Ref k=Ref(x);
	k.inc_freq();
	mem_perm.push_back(k);mem_perm_size++;
	arr[x]=mem_perm.begin();

	while(cin>>x)
	{
		if(arr[x]==temp.end())
		{
			miss++;
			Ref k=Ref(x);
			k.inc_freq();
			list<Ref>::iterator pos=mem_perm.begin();
			int j3=0;
			for(;pos->getfreq()>k.getfreq() && pos!=mem_perm.end();pos++){j3++;}
			if(j3>=frames){pos=mem_perm.end();pos--;}
			mem_perm.insert(pos,k);
			pos--;
			arr[x]=pos;
			mem_perm_size++;
		}
		else if (arr[x]->getval()==x)
		{
			hit++;
			arr[x]->inc_freq();
			Ref t=*arr[x];
			mem_perm.erase(arr[x]);
			list<Ref>::iterator pos=mem_perm.begin();
			int j3=0;
			for(;pos->getfreq()>t.getfreq() && pos!=mem_perm.end();pos++){j3++;}
			if(j3>=frames){pos=mem_perm.end();pos--;}
			mem_perm.insert(pos,t);
			if(pos!=mem_perm.begin()){pos--;}
			arr[x]=pos;
		}
		if(mem_perm_size>frames)
		{
			list<Ref>::iterator pos1=mem_perm.end();
			pos1--;
			mem_perm.erase(pos1);
			arr[pos1->getval()]=temp.end();
			mem_perm_size--;	
		}
	}
	cout<<hit<<endl;
	cout<<miss;
}