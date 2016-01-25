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
	int max_id;cin>>max_id;
	int frames;cin>>frames;
	int pages;cin>>pages;

	if(frames>=pages)
	{
		cout<<pages<<endl;
		cout<<"0"<<endl;
		return 0;
	}
	int x;
	//int mem_perm_curr_size=0;
	bool guess_present_in_mem_perm=0;
	int hit=0, miss=0;
	//int i1=0;
	while(cin>>x)
	{
		//++i1;
		guess_present_in_mem_perm=0;
		//if(mem_temp_curr_size<frames)
		//if the no. is already present in mem
			//if yes, update its frequency
			//if no, create another in the mem
		//int j1=0;
		int j2=0;
		for(list<Ref>::iterator perm_obj=mem_perm.begin();
			perm_obj!=mem_perm.end() && j2<frames;perm_obj++)
		{
			j2++;
			if(perm_obj->getval()==x)
			{
				hit++;
				perm_obj->inc_freq();
				Ref t = *perm_obj;
				mem_perm.erase(perm_obj);
				list<Ref>::iterator pos=mem_perm.begin();
				int j3=0;
				for(;pos->getfreq()>t.getfreq() && pos!=mem_perm.end();pos++){j3++;}
				if(j3>=frames){pos=mem_perm.end();pos--;}
				mem_perm.insert(pos,t);
				guess_present_in_mem_perm=1;
				break;
			}
		}
		if(!guess_present_in_mem_perm)
		{
			miss++;
			Ref k=Ref(x);
			k.inc_freq();
			list<Ref>::iterator pos=mem_perm.begin();
			int j3=0;
			for(;pos->getfreq()>k.getfreq() && pos!=mem_perm.end();pos++){j3++;}
			//cout<<x<<' '<<j3<<endl;
			if(j3>=frames){pos=mem_perm.end();pos--;}
			mem_perm.insert(pos,k);
			//mem_perm_curr_size++;
		}


		// for(list<Ref>::iterator j=mem_perm.begin(); j != mem_perm.end(); ++j) cout << j->getval() << " ";
		// cout<<endl<<"hit"<<' '<<hit<<endl;
		// cout<<"miss"<<' '<<miss<<endl<<endl;

	}
	//for(list<Ref>::iterator j=mem_perm.begin(); j != mem_perm.end(); ++j) cout << j->getval() << " "<<j->getfreq()<<endl;
	//cout<<mem_perm_curr_size<<endl;
	cout<<hit<<endl;
	cout<<miss<<endl;
	
	//for(list<int>::iterator j=l.begin(); j != l.end(); ++j) cout << *j << " ";

}