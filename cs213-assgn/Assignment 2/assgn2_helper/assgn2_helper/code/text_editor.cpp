#include <iostream>
#include <stack>
#include <string.h>
#include <assert.h>

using namespace std;

class text_editor
{
private:
	stack<char> s;
	stack<char> bin;
	stack<char> bin2;
	int unre;
	class char_num
	{
	public:
		char c;
		int num;
		char_num(char c1, int num1)
		{
			c = c1;
			num = num1;
		}
	};
	stack<char_num> command;
	stack<char_num> undo_redo;

public:
	text_editor()
	{
		unre = 0;
	}
	void append(string w)
	{
		char to_append[w.length()];
		strcpy(to_append,w.c_str());
		for(int i = 0;i<w.size();i++)
		{
			//cout<<to_append[i]<<endl;
			s.push(to_append[i]);
			//cout<<s.top()<<endl;
		}
		char_num x = char_num('a',w.length());
		command.push(x);
		for(int i = 0; i<unre;i++)
		{
			undo_redo.pop();
		}
		unre = 0;
		return;
	}
	void erase(int k)
	{
		for(int i = 0; i<k; i++)
		{
			bin.push(s.top());
			s.pop();
		}
		//cout<<"line 56 "<<s.size()<<endl;
		char_num x = char_num('e',k);
		command.push(x);
		for(int i = 0; i<unre;i++)
		{
			undo_redo.pop();
		}
		unre = 0;
		return;
	}
	char get(int k)
	{
		assert (k < s.size());
		stack<char> s1;
		s1 = s;
		int n = s1.size();
		for(int i = 1; i < n - k;i++)
		{
			s1.pop();
		}
		return s1.top();
	}
	void undo()
	{
		if (command.top().c== 'a')
		{
			int i = command.top().num;
			for(int j = 0; j < i;j++)
			{
				bin2.push(s.top());
				s.pop();
			}
			undo_redo.push(command.top());
			unre++;
			command.pop();
		}
		else if (command.top().c == 'e')
		{
			int i = command.top().num;
			for(int j = 0; j < i;j++)
			{
				s.push(bin.top());
				bin.pop();
			}
			undo_redo.push(command.top());
			unre++;
			command.pop();
		}
		return;
	}

	void redo()
	{
		if (unre == 0)
		{
			return;
		}
		if (undo_redo.top().c == 'a')
		{
			for(int i = 0; i < undo_redo.top().num;i++)
			{
				s.push(bin2.top());
				bin2.pop();
			}
			command.push(undo_redo.top());
			undo_redo.pop();
			//cout<<"line 120"<<undo_redo.size();
			unre--;
		}
		else if (undo_redo.top().c == 'e')
		{
			for(int i = 0;i < undo_redo.top().num; i++)
			{
				bin.push(s.top());
				s.pop();
			}
			command.push(undo_redo.top());
			undo_redo.pop();
			unre--;
		}
		return;
	}

	void print()
	{
		stack<char> s1;
		stack<char> s2;
		s1 = s;
		int n = s1.size();
		for(int i = 0; i < n;i++)
		{
			s2.push(s1.top());
			s1.pop();
		}
		for(int i = 0; i < n; i++)
		{
			cout<<s2.top();
			s2.pop();
		}
		cout<<endl;
	}
};

int main()
{
	int Q; cin>>Q;
	text_editor te;
	char c;
	for(int j = 0;j < Q; j++)
	{
		cout<<"iter "<<j<<endl;
		cin>>c;
		if (c == 'a')
		{
			string x;
			cin>>x;
			te.append(x);
		}
		else if(c == 'e')
		{
			int z;
			cin>>z;
			te.erase(z);
		}
		else if(c=='g')
		{
			int z;
			cin>>z;
			cout<<te.get(z)<<endl;
		}
		else if(c == 'u')
		{
			te.undo();
		}
		else if(c == 'r')
		{
			te.redo();
		}
		te.print();
	}
}

// int main()
// {
// 	text_editor a;
// 	a.append("hello");
// 	a.append(" ");
// 	a.append("world");
// 	//a.undo();
// 	//a.erase(1);
// 	a.redo();
// 	//a.erase(3)
// 	a.print();
// }