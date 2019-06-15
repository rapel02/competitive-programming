#include<bits/stdc++.h>
using namespace std;

int vis[1500];

bool v[250][250];
bool bicolor;
int n,tc;

void coloring(int pos,int col)
{
	for(int a=0;a<tc;a++)
	{
		if(v[pos][a]==true)
		{
			if(vis[a]==-1)
			{
				vis[a] = 1 - col;
				coloring(a,1-col);
			}
			else if(vis[a]!=1-col)
			{
				bicolor = false;
				return ;
			}
		}
	}
	return ;
}

int main()
{
	while(1)
	{
		memset(vis,-1,sizeof(vis));
		memset(v,false,sizeof(v));
		scanf("%d",&tc);
		if(tc==0) break;
		scanf("%d",&n);
		for(int a=0;a<n;a++)
		{
			int t,f;
			scanf("%d %d",&t,&f);
			v[t][f] = v[f][t] = true;
		}
		bicolor = true;
		for(int a=0;a<tc;a++)
		{
			if(vis[a]==-1)
			{
				vis[a] = 0;
				coloring(a,0);
			}
		}
		if(bicolor==false) printf("NOT ");
		printf("BICOLORABLE.\n");
	}
}
