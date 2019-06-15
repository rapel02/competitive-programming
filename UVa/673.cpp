#include<bits/stdc++.h>
using namespace std;

stack<char> st;

char in[200];

int main()
{
	int t;
	scanf("%d",&t); getchar();
	for(int a=1;a<=t;a++)
	{
		gets(in);
		int len = strlen(in);
		for(int b=0;b<len;b++)
		{
			if(in[b]=='(' || in[b]=='[') st.push(in[b]);
			else
			{
				if(st.empty()==false)
				{
					if(st.top()=='(' && in[b]==')') st.pop();
					else if(st.top()=='[' && in[b]==']') st.pop();
					else st.push(in[b]);
				}
				else st.push(in[b]);
			}
		}
		if(st.empty()==true) printf("Yes\n");
		else printf("No\n");
		while(st.empty()==false) st.pop();
	}
}
