#include<bits/stdc++.h>
using namespace std;

int vis[1<<16];
int arr[50];

queue<int> q;

int main()
{
	int ntc;
	int n,m;
	scanf("%d",&ntc);
	for(int tc=1;tc<=ntc;tc++)
	{
		scanf("%d %d",&n,&m);
		for(int a=0;a<m;a++)
		{
			int val = 0;
			int q;
			scanf("%d",&q);
			for(int b=0;b<q;b++)
			{
				int t;
				scanf("%d",&t);
				val =val + (1<<t);
			}
			arr[a] = val;
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
				int val = pos ^ arr[a];
				if(vis[val]!=-1) continue;
				vis[val] = vis[pos] + 1;
				q.push(val);
			}
		}
		int q;
		scanf("%d",&q);
		printf("Case %d:\n",tc);
		for(int a=0;a<q;a++)
		{
			char in[20];
			scanf("%s",in);
			int len = strlen(in);
			int tot = 0;
			for(int a=0;a<len;a++)
				tot = tot * 2 + in[a]-'0';
			printf("%d\n",vis[tot]);
		}
		printf("\n");
	}
}
