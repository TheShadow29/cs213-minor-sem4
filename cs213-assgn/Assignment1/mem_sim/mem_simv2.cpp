#include <iostream>
#include <fstream>
#include <list>
using namespace std;

class Ref
{
public:
	int freq,val;
	Ref(int value=0)
	{
		freq=0;
		val=value;
	}
	void inc_freq(){freq++;}
	int getval(){return val;}
	int getfreq(){return freq;}
	void set_val(int value){val=value;}
};

class mem_temp
{
private:
	int frames;
public:
	mem_temp(int p)
	{
		frames=p;
		list<Ref> mem_perm;
	}
	int update()
	{

	}
};

int main()
{
	list<Ref> mem_perm;
	int N;cin>>N;
	int P;cin>>P;
	int M;cin>>M;

	if(P>=M)
	{
		cout<<M<<endl;
		cout<<"0"<<endl;
		return 0;
	}
	Ref* arr1[M];
	for(int i=0;i<M;i++){arr1[i]=NULL;}
	int x,hit=0,miss=0;
	while(cin>>x)
	{
		if(arr1[x-1]!=NULL && arr1[x-1]->getval()==x)
		{
			arr1[x-1]->inc_freq();
			hit++;
			Ref t = *arr1[x-1];
			mem_perm.erase(arr1[x-1]);
			list<Ref>::iterator pos=mem_perm.begin();
			int j3=0;
			for(;pos->getfreq()>t.getfreq() && pos!=mem_perm.end();pos++){j3++;}
			if(j3>=P){pos=mem_perm.end();pos--;}
			mem_perm.insert(pos,t);
		}
		else 
		{
			miss++;
			Ref k = Ref(x);
			arr1[x-1]=&k;
			arr1[x-1]->inc_freq();
			list<Ref>::iterator pos=mem_perm.begin();
			int j3=0;
			for(;pos->getfreq()>k.getfreq() && pos!=mem_perm.end();pos++){j3++;}
			if(j3>=P){pos=mem_perm.end();pos--;}
			mem_perm.insert(pos,k);
		}
	}
	cout<<hit<<endl;
	cout<<miss;
	// Ref k = Ref(2);
	// mem_perm.push_back(k);
	// list<Ref>::iterator j=mem_perm.begin();
	// arr1[1]=&(*j);
	// //arr1[1]->inc_freq();
	// list<Ref>::iterator j1=mem_perm.begin();
	// cout<<j1->getfreq();
	// //int x;

}