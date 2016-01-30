#include <iostream>
#include <string>
using namespace std;

class Height
{
public:
	int val;
	string unit;

	Height(int h, string a)
	{
		val = h;
		unit = a;
		return;
	}
	Height()
	{
		val = 0;
		unit = "cm";
		return;
	}

	Height operator++()	//prefix form
	{
		Height res;
		res.val = ++val;
		res.unit = this->unit;
		return res;
	}

	Height operator++(int i)	//postfix form
	{
		Height res;
		res.val = val++;
		res.unit = this -> unit;
		return res;
	}

	Height operator+(Height b)
	{
		//assume b and this have the same units
		Height res;
		res.val = this->val + b.val;
		res.unit = unit;
		return res;
	}
};

int main()
{
	Height a(176, "cm"), b(180, "cm"),c;
	cout << "a = " << a.val << a.unit<< endl;
	cout << "b = " << b.val << b.unit << endl;
	c = ++a;
	cout << " ++a = " << c.val << c.unit << endl;
	c = a++;
	cout << " a++ = " << c.val << c.unit << endl;
	c = a++ + ++b;
	cout << " a++ + ++b = " << c.val << c.unit << endl;
}

// int main()
// {
// 	Height a(176, "cm"), b(180, "cm"),c;
// 	cout << " a = " << a.val << a.unit<< endl;
// 	cout << " b = " << b.val << b.unit << endl;
// 	c = a.operator++();	//prefix form
// 	cout << " ++a = " << c.val << c.unit << endl;
// 	c = a.operator++(0); //postfix form
// 	cout << " a++ = " << c.val << c.unit << endl;
// 	c = a.operator++(0).operator+( b.operator++());
// 	cout << " a++ + ++b = " << c.val << c.unit << endl;
// }