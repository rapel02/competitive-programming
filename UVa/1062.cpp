#include<bits/stdc++.h>
using namespace std;

string in;

stack<char> s[1500];

bool tot[150];

int main()
{
	int tc = 0;
	while(cin>>in)
	{
		tc++;
		if(in=="end") break;
		memset(tot,false,sizeof(tot));
		int ans = 0;
		int len = in.length();
		for(int a=0;a<len;a++)
		{
			if(tot[in[a]]==false) ans++;
			tot[in[a]] = true;
		}
		int idx = 0;
		for(int a=0;a<len;a++)
		{
			bool ins = false;
			for(int b=0;b<idx;b++)
			{
				if(s[b].top() >= in[a])
				{
					s[b].push(in[a]);
					ins = true;
					break;
				}
			}
			if(ins==false)
			{
				s[idx].push(in[a]);
				idx++;
			}
		}
		printf("Case %d: %d\n",tc,min(idx,ans));
		for(int a=0;a<idx;a++)
		{
			while(!s[a].empty()) s[a].pop();
		}
	}
}
