#include<bits/stdc++.h>
using namespace std;

char in[150];
stack<char> s;

char rev(char a)
{
	if(a==')') return '(';
	else if(a==']') return '[';
	else if(a=='(') return ')';
	else return ']';
}

int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%s",in);
		int len = strlen(in);
		for(int a=0;a<len;a++)
		{
			char c = in[a];
			if(c=='(' || c=='[')
			{
				printf("%c",c);
				s.push(c);
			}
			else
			{
				char re = rev(c);
				if(s.empty() || s.top()!=re) printf("%c%c",re,c);
				else
				{
					printf("%c%c",re,c);
					s.pop();
				}
			}
		}
		while(!s.empty())
		{
			char nx = s.top();
			printf("%c",rev(nx));
			s.pop();
		}
		printf("\n");
		if(n!=0) printf("\n");
	}
}
