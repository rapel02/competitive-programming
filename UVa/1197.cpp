#include<bits/stdc++.h>
using namespace std;

vector <int> vec[30005];
bool vis[30005];

void floodfill(int pos)
{
	int sz = vec[pos].size();
	vis[pos] = true;
	for(int a=0;a<sz;a++)
	{
		int next = vec[pos][a];
		if(vis[next]==false)
		{
			vis[next] = true;
			floodfill(next);
		}
	}
}

int main()
{
	int n,m,k;
	while(1)
	{
		scanf("%d %d",&n,&m);
		if(n+m==0) break;
		memset(vis,false,sizeof(vis));
		for(int a=0;a<m;a++)
		{
			int k,now,prev;
			scanf("%d",&k);
			for(int b=0;b<k;b++)
			{
				scanf("%d",&now);
				if(b!=0)
				{
					vec[prev].push_back(now);
					vec[now].push_back(prev);
				}
				prev = now;
			}
		}
		int tot = 0;
		floodfill(0);
		for(int a=0;a<n;a++) 
		{
			if(vis[a]==true) tot++;
			vec[a].clear();
		}
		printf("%d\n",tot);
	}
}
