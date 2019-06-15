#include<bits/stdc++.h>
using namespace std;

map<int,int> mmap;
vector<int> vec[1500];
int n;
int vis[1500];

int main()
{
	int tc = 0;
	int E;
	while(scanf("%d",&E)!=EOF)
	{
		if(E == 0) break;
		int k = 0;
		mmap.clear();
		for(int a=0;a<E;a++)
		{
			int s,d;
			scanf("%d %d",&s,&d);
			if(mmap[s] == 0) mmap[s] = ++k;
			if(mmap[d] == 0) mmap[d] = ++k;
			vec[mmap[s]].push_back(mmap[d]);
			vec[mmap[d]].push_back(mmap[s]);
		}
		while(1)
		{
			int s,d;
			scanf("%d %d",&s,&d);
			memset(vis,-1,sizeof(vis));
			if(s ==0 && d == 0) break;
			vis[mmap[s]] = 0;
			tc++;
			queue<int> q;
			int tot = 0;
			q.push(mmap[s]);
			while(!q.empty())
			{
				int pos = q.front();
				q.pop();
				tot++;
				if(vis[pos] == d) continue;
				for(int a=0;a<vec[pos].size();a++)
				{
					int nx = vec[pos][a];
					if(vis[nx] == -1)
					{
						vis[nx] = vis[pos] + 1;
						q.push(nx);
					}
				}
			}
			printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",tc,k - tot,s,d);
		}
		for(int a=0;a<=k;a++) vec[a].clear();
	}
}
