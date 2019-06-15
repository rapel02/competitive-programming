#include<bits/stdc++.h>
using namespace std;

int nh[255],ph[255],nm[255],pm[255];
int dist[255][255];
int val[255];
int vis[255];
bool seen[255];

int llo[255][255],hhi[255][255];


int H,A;

bool observe(int pos,int vis[],int dday,bool seen[])
{
	for(int a=0;a<A;a++)
	{
		if(!seen[a] && nm[a]+dday*pm[a]>=llo[pos][a] &&nm[a]+dday*pm[a]<=hhi[pos][a])
		{
			seen[a]=true;
			if(vis[a] < 0 ||observe(vis[a],vis,dday,seen))
			{
				vis[a]=pos;
				return true;
			}
		}
	}
	return false;
}

int maxBPM(int dday)
{
	for(int a=0;a<H;a++)
		val[a]=nh[a]+ph[a]*dday;
	int res=0;
	memset(vis,-1,sizeof(vis));
	
	for(int a=0;a<H;a++)
	{
		memset(seen,false,sizeof(seen));
		if(observe(a,vis,dday,seen)==true) res++;
	}
	return res;
}

int main()
{
	while(1)
	{
		scanf("%d %d",&H,&A);
		if(H==0&&A==0) break;
		for(int a=0;a<H;a++)
			scanf("%d %d",&nh[a],&ph[a]);
		for(int a=0;a<A;a++)
			scanf("%d %d",&nm[a],&pm[a]);
		for(int a=0;a<H;a++)
		{
			for(int b=0;b<A;b++)
			{
				if(ph[a]==pm[b])
				{
					if(nh[a]>=nm[b]) llo[a][b]=0,hhi[a][b]=100000;
					else llo[a][b]=-1,hhi[a][b]=-1;
				}
				else
				{
					
				}
			}
		}
		for(int a=0;a<H;a++)
			for(int b=0;b<A;b++) scanf("%d",&dist[a][b]);
		int lo=0;
		int hi=40002;
		int res=-1;
		while(lo<=hi)
		{
			int mid=(lo+hi)/2;
			if(maxBPM(mid)==(A))
			{
				hi=mid-1;
				res=mid;
			}
			else lo=mid+1;
		}
		if(res==-1) printf("IMPOSSIBLE\n");
		else printf("%d\n",res);
	}
}
