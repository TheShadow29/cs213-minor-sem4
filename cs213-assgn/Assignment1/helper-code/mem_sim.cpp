#include <iostream>
#include <fstream>
#include <list>
using namespace std;
/*
By careful manipulation there may be a way to not use last_used, and keep
memory in sorted order always
This way the search algorithm will also be in O(logn)
Overall complexity may be O(n)
*/
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
	list<Ref> mem_temp;
	list<Ref> mem_perm;
	ifstream ifile;
	ifile.open("input.txt");
	int max_id;ifile>>max_id;
	int frames;ifile>>frames;
	int pages;ifile>>pages;

	if(frames>=pages)
	{
		cout<<pages<<endl;
		cout<<"0"<<endl;
		return 0;
	}
	int x;
	int mem_perm_curr_size=0;
	int mem_temp_curr_size=0;
	bool guess_present_in_mem_perm=0;
	bool guess_present_in_mem_temp=0;
	int hit=0, miss=0;
	//int i1=0;
	while(ifile>>x)
	{
		//++i1;
		guess_present_in_mem_perm=0;
		//if(mem_temp_curr_size<frames)
		//if the no. is already present in mem
			//if yes, update its frequency
			//if no, create another in the mem
		
		for(list<Ref>::iterator perm_obj=mem_perm.begin();
			perm_obj!=mem_perm.end();perm_obj++)
		{
			if(perm_obj->getval()==x)
			{
				perm_obj->inc_freq();
				guess_present_in_mem_perm=1;
				break;
			}
		}
		if(!guess_present_in_mem_perm)
		{
			Ref k=Ref(x);
			k.inc_freq();
			mem_perm.push_back(k);
			mem_perm_curr_size++;
		}
		for(list<Ref>::iterator temp_obj=mem_temp.begin();
			temp_obj!=mem_temp.end();temp_obj++)
		{
			if (temp_obj->getval()==x)
			{
				guess_present_in_mem_temp=1;
				break;
			}
		}
		if(!guess_present_in_mem_temp)
		{
			miss++;
			if(mem_temp_curr_size<frames)
			{
				mem.temp_obj
			}
		}
	}
	for(list<Ref>::iterator j=mem_perm.begin(); j != mem_perm.end(); ++j) cout << j->getval() << " "<<j->getfreq()<<endl;
	cout<<mem_perm_curr_size<<endl;
	
	//for(list<int>::iterator j=l.begin(); j != l.end(); ++j) cout << *j << " ";

}
