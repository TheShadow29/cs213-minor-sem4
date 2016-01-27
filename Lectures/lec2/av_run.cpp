#include <iostream>
#include <string>
using namespace std;

class hrminsec
{
public:
	short hr;
	short min;
	float sec;
	hrminsec()
	{
		hr=0;min=0;sec=0;
	}
};

int s2i (string s)
{ 
	int num = 0, digit = 0;
	for ( int j = 0 ; j < s.size(); j++)
	{ 
		switch (s[j]) 
		{
			case ('0') : digit = 0; break;
			case ('1') : digit = 1; break;
			case ('2') : digit = 2; break;
			case ('3') : digit = 3; break;
			case ('4') : digit = 4; break;
			case ('5') : digit = 5; break;
			case ('6') : digit = 6; break;
			case ('7') : digit = 7; break;
			case ('8') : digit = 8; break;
			case ('9') : digit = 9; break;
		}; // end of switch
		num = num*10 + digit;
	};
	return num;
};

float s2f(string s)
{ 
	string left, right;
	short dot = s.find('.');
	if ( dot < 0 && dot > s.length() )
	{
		cerr << " dot not in string \n"; return -1.0;
	}
	left = s.substr(0, dot);
	right = s.substr(dot+1, s.length() - dot - 1);
	int whole, fract;
	whole = s2i(left);
	fract = s2i(right);
	float val = fract;
	for ( int i = 0; i < right.length(); i++) val = val * 0.1;
	val = val + whole;
	return val;
}


hrminsec* parse(string s)
{
	string strh="",strm="",strs="";
	short hr=0,min=0;
	float sec=0;
	int indexH=-1,indexM=-1,indexS=-1;
	
	indexH = s.find('h');

	if (indexH > 0 && indexH < s.length())
	{
		strh = s.substr(0,indexH);
		s = s.substr(indexH+1,s.length() - indexH - 1);
	}

	indexM = s.find('m');
	if (indexM > 0 && indexM < s.length())
	{
		strm = s.substr(0,indexM);
		s = s.substr(indexM+1,s.length() - indexM - 1);
	}

	indexS = s.find('s');
	if (indexS==s.length()-1)
	{
		strs = s.substr(0,indexS);
	}

	hr  = s2i(strh);
	min = s2i(strm);
	sec = s2f(strs);
	
	hrminsec* p = new hrminsec();
	p->hr = hr;
	p->min = min;
	p->sec = sec;
	//cout<<p->hr<<" "<<p->min<<" "<<p->sec<<endl;
	return p;
}


int main()
{
	string str, ti;
	hrminsec* x;
	while(cin>>str>>ti)
	{
		if (str == "real")
		{
			x=parse(ti);
		}
	}
	cout<<x->hr<<"h"<<x->min<<"m"<<x->sec<<"s";
}

