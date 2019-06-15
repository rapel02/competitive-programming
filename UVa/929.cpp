#include<bits/stdc++.h>
#define inf 1e+9
using namespace std;

int f[1000][1000],dist[1000][1000];
int x[]={0,0,-1,1};
int y[]={1,-1,0,0};
priority_queue<pair<int, pair<int,int> > > pq;

int dijk(int r,int c)
{
	pq.push(make_pair(-f[0][0],make_pair(0,0)));
	while(!pq.empty())
	{
		int posy = pq.top().second.first;
		int posx = pq.top().second.second;
		int val = -pq.top().first;
		pq.pop();
		if(posy==r-1 && posx==c-1)
		{
			while(!pq.empty()) pq.pop();
			return val;
		}
		for(int a=0;a<4;a++)
		{
			int xx = posx + x[a];
			int yy = posy + y[a];
			if(xx<0 ||xx>=c ||yy<0 ||yy>=r) continue;
			if(dist[yy][xx]>val+f[yy][xx])
			{
				dist[yy][xx] = val+f[yy][xx];
				pq.push(make_pair(-(val+f[yy][xx]),make_pair(yy,xx)));
			}
		}
	}
}

int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		int r,c;
		scanf("%d %d",&r,&c);
		for(int a=0;a<r;a++)
			for(int b=0;b<c;b++) dist[a][b] = inf;
		for(int a=0;a<r;a++)
			for(int b=0;b<c;b++) scanf("%d",&f[a][b]);
		dist[0][0] = 0;
		printf("%d\n",dijk(r,c));
	}
}
