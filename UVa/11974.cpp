#include<bits/stdc++.h>
using namespace std;

int arr[150];
int vis[1<<16];

queue<int> q;

int main()
{
	int ntc;
	scanf("%d",&ntc);
	for(int tc=1;tc<=ntc;tc++)
	{
		int n,m;
		scanf("%d %d",&n,&m);
		for(int a=0;a<m;a++)
		{
			int tot = 0;
			for(int b=0;b<n;b++)
			{
				int t;
				scanf("%d",&t);
				tot = tot + t*(1<<b);
			}
			arr[a] = tot;
		}
		memset(vis,-1,sizeof(vis));
		vis[0] = 0;
		q.push(0);
		while(!q.empty())
		{
			int pos = q.front();
			q.pop();
			for(int a=0;a<m;a++)
			{
				int nx = pos ^ arr[a];
				if(vis[nx]!=-1) continue;
				vis[nx] = vis[pos] + 1;
				q.push(nx);
			}
		}
		printf("Case %d: ",tc);
		if(vis[(1<<n)-1]==-1) printf("IMPOSSIBLE\n");
		else printf("%d\n",vis[(1<<n)-1]);
	}
}
