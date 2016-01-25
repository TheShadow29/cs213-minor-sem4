#include <iostream>
#include <fstream>
#include <list>
using namespace std;

// class Ref
// {
// public:
// 	int freq,val;
// 	Ref(int value)
// 	{
// 		freq=0;
// 		val=value;
// 	}
// 	void inc_freq(){freq++;}
// 	int getval(){return val;}
// 	int getfreq(){return freq;}
// };

int main()
{
	//list<Ref> mem_perm;
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
	int hit=0, miss=0;

	list<list<int>*> mem_temp;	//page ptr
	int page_freq[pages];	//page freq

	

		//for(list<Ref>::iterator j=mem_perm.begin(); j != mem_perm.end(); ++j) cout << j->getval() << " ";
		//cout<<endl<<"hit"<<' '<<hit<<endl;
		//cout<<"miss"<<' '<<miss<<endl<<endl;

	}
	//for(list<Ref>::iterator j=mem_perm.begin(); j != mem_perm.end(); ++j) cout << j->getval() << " "<<j->getfreq()<<endl;
	//cout<<mem_perm_curr_size<<endl;
	cout<<hit<<endl;
	cout<<miss<<endl;
	
	//for(list<int>::iterator j=l.begin(); j != l.end(); ++j) cout << *j << " ";

}