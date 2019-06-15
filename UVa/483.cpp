#include<bits/stdc++.h>
using namespace std;

stack<char> s;

int main()
{
	char t;
	while(scanf("%c",&t)!=EOF)
	{
		if(t!=' '&&t!='\n')
		{
			s.push(t);
		}
		else
		{
			while(!s.empty())
			{
				printf("%c",s.top());
				s.pop();
			}
			printf("%c",t);
		}
	}
}
