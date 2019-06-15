#include<bits/stdc++.h>
using namespace std;

int vis[1500];

queue<int> q;
vector<int> v[250];

int main()
{
	int tc;
	while(1)
	{
		int n;
		memset(vis,-1,sizeof(vis));
		scanf("%d",&tc);
		if(tc==0) break;
		scanf("%d",&n);
		for(int a=0;a<n;a++)
		{
			int t,f;
			scanf("%d %d",&t,&f);
			v[t].push_back(f);
			v[f].push_back(t);
		}
		bool bicolor = true;
		for(int a=0;a<tc;a++)
		{
			if(vis[a]==-1)
			{
				vis[a] = 0;
				q.push(a);
				while(!q.empty())
				{
					int pos = q.front();
					q.pop();
					int sz = v[pos].size();
					for(int b=0;b<sz;b++)
					{
						int nm = v[pos][b];
						if(vis[nm]==-1)
						{
							vis[nm] = 1^vis[pos];
							q.push(v[pos][b]);
						}
						else if(vis[nm]!=1^vis[pos])
						{
							bicolor = false;
						}
					}
				}
			}
		}
		if(bicolor==false) printf("NOT ");
		printf("BICOLORABLE.\n");
		for(int a=0;a<tc;a++) v[a].clear();
	}
}
