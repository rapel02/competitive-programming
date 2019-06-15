#include<bits/stdc++.h>
#define mod 1000000
using namespace std;

int vis[1000000];

queue<int> q;

int main()
{
	int f,t;
	while(scanf("%d %d",&f,&t)!=EOF)
	{
		memset(vis,-1,sizeof(vis));
		vis[f] = 0;
		while(!q.empty()) q.pop();
		q.push(f);
		while(!q.empty())
		{
			int pos = q.front();
			if(pos==t) break;
			q.pop();
			int add = 111000;
			for(int a=0;a<7;a++)
			{
				int nx = (pos + add) % mod;
				if(vis[nx]==-1)
				{
					q.push(nx);
					vis[nx] = vis[pos] + 1;
				}
				nx = (1000000 + (pos - add)) % mod;
				if(vis[nx]==-1)
				{
					q.push(nx);
					vis[nx] = vis[pos] + 1;
				}
				add/=10;
			}
			add = 110000;
			for(int a=0;a<7;a++)
			{
				int nx = (pos + add) % mod;
				if(vis[nx]==-1)
				{
					q.push(nx);
					vis[nx] = vis[pos] + 1;
				}
				nx = (1000000 + (pos - add)) % mod;
				if(vis[nx]==-1)
				{
					q.push(nx);
					vis[nx] = vis[pos] + 1;
				}
				add/=10;
			}	
			add = 100000;
			for(int a=0;a<7;a++)
			{
				int nx = (pos + add) % mod;
				if(vis[nx]==-1)
				{
					q.push(nx);
					vis[nx] = vis[pos] + 1;
				}
				nx = (1000000 + (pos - add)) % mod;
				if(vis[nx]==-1)
				{
					q.push(nx);
					vis[nx] = vis[pos] + 1;
				}
				add/=10;
			}			
		}
		printf("%d\n",vis[t]);
	}
}
