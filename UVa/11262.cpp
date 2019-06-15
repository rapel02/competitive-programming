#include<bits/stdc++.h>
using namespace std;

struct Point{
	int x,y;
}temp,red[150],blue[150];

bool vis[150];
int pos[150];
int rr = 0,bb = 0;

int sqr(int a)
{
	return a*a;
}

int dist(int a,int b)
{
	return sqr(red[a].x - blue[b].x) + sqr(red[a].y - blue[b].y);
}

bool Aug(int m,int r)
{
	if(vis[m]==true) return false;
	vis[m] = true;
	for(int a=0;a<bb;a++)
	{
		if((dist(m,a) <= r*r && (pos[a]==-1 || Aug(pos[a],r))))
		{
			pos[a] = m;
			return true;
		}
	}
	return false;
}

int MCBM(int r)
{
	int ans = 0;
	memset(pos,-1,sizeof(pos));
	for(int a=0;a<rr;a++)
	{
		memset(vis,false,sizeof(vis));
		if(Aug(a,r)) ans++;
	}
	return ans;
}

int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		int n,k;
		scanf("%d %d",&n,&k);
		char in[10];
		rr=0,bb=0;
		for(int a=0;a<n;a++)
		{
			scanf("%d %d %s",&temp.x,&temp.y,in);
			if(strcmp(in,"red")==0) red[rr++] = temp;
			else blue[bb++] = temp;
		}
		if(rr<k || bb<k) printf("Impossible\n");
		else
		{
			int lo = 0;
			int hi = 1413;
			int ans = -1;
			while(lo<=hi)
			{
				int mid = (lo+hi)/2;
				int c = MCBM(mid);
				if(c>=k) ans = mid,hi = mid-1;
				else lo = mid+1;
			}
			printf("%d\n",ans);
		}
	}
}
