#include<bits/stdc++.h>
using namespace std;

string in,temp;

void convert(int in)
{
	stack<int> s;
	while(in!=0) 
	{
		s.push(in%10);
		in/=10;
	}
	temp = "";
	while(!s.empty()) temp += (s.top() + '0'), s.pop();
}

int main()
{
	while(cin>>in)
	{
		if(in == "END") break;
		int x = 0;
		while(1)
		{
			int len = in.length();
			convert(len);
			if(in == temp)
			{
				printf("%d\n",x + 1);
				break;
			}
			in = temp;
			x++;
		}
	}
}
