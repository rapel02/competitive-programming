#include<bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
using namespace std;

int par[1000],h[1000];

int find(int a)
{
	if(a==par[a]) return a;
	return par[a] = find(par[a]);
}

bool issame(int a,int b)
{
	return find(a)==find(b);
}

void disjoint(int a,int b)
{
	int x = find(a);
	int y = find(b);
	if(h[x] > h[y])
	{
		par[y] = x;
	}
	else
	{
		par[x] = y;
		if(h[x]==h[y]) h[y]++;
	}
}

struct Pos{
	double x,y;
}p[1000];

double sqr(double x)
{
	return x*x;
}

double dist(int a,int b)
{
	return sqrt(sqr(p[a].x - p[b].x) + sqr(p[a].y - p[b].y) );
}

priority_queue<pair<double,pair<int,int> > >pq;

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		for(int a=1;a<=n;a++) scanf("%lf %lf",&p[a].x,&p[a].y);
		for(int a=1;a<=n;a++) h[a] = 1,par[a] = a;
		int m;
		scanf("%d",&m);
		double tot = 0;
		for(int a=1;a<=m;a++)
		{
			int x,y;
			scanf("%d %d",&x,&y);
			//tot += dist(x,y);
			disjoint(x,y);
		}
		for(int a=1;a<=n;a++)
		{
			for(int b=a+1;b<=n;b++)
				pq.push(mp(-dist(a,b),mp(a,b)));
		}
		while(!pq.empty())
		{
			double val = -pq.top().ff;
			int aa = pq.top().ss.ff;
			int bb = pq.top().ss.ss;
			pq.pop();
			if(issame(aa,bb)==false)
			{
				tot += val;
				disjoint(aa,bb);
			}
		}
		printf("%.2lf\n",tot);
	}
}
