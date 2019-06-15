#include<bits/stdc++.h>
#define bff getchar()
using namespace std;

int hub[1000][1000];
int ans;
int bo,nu;
bool vis[1000];
int val[1000];

int match(int idx)
{
	if(idx==-1) return true;
	for(int b=0;b<nu;b++)
	{
		//printf("%d %d\n",idx,b);
		if(hub[idx][b]!=0 && vis[b]==false)
		{
			vis[b]=true;
			if(val[b]==-1||match(val[b]))
			{
				//printf("clear\n");
				val[b]=idx;
				return true;
			}
		}
		//bff;
	}
	return false;
}

int mcbm()
{
	for(int a=0;a<bo;a++)
	{
		memset(vis,false,sizeof(vis));
		if(match(a))
		ans++;
		//printf("%d\n\n",a);
	}
	return ans;
}

int main()
{
	int test;
	scanf("%d",&test); bff;
	for(int a=1;a<=test;a++)
	{
		scanf("%d %d",&bo,&nu); bff;
		ans=0;
		for(int b=0;b<bo;b++)
			for(int c=0;c<nu;c++)
				scanf("%d",&hub[b][c]),bff;
		memset(val,-1,sizeof(val));
		printf("Case %d: a maximum of %d nuts and bolts can be fitted together\n",a,mcbm());
	}
}

