#include<bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
using namespace std;

struct Point{
	double x,y;
}p[105];

int par[105],h[105];

priority_queue<pair<double,pair<int,int> > > pq;

double sqr(double a)
{
	return a*a;
}

double dist(int a,int b)
{
	return sqrt(sqr(p[a].x - p[b].x) + sqr(p[a].y - p[b].y));
}

int findset(int a)
{
	return (par[a]==a)?a: (par[a] = findset(par[a]) );
}

bool issame(int a,int b)
{
	return findset(a) == findset(b);
}

void join(int a,int b)
{
	int x = findset(a);
	int y = findset(b);
	if(h[x]>h[y])
	{
		par[y] = x;
	}
	else
	{
		par[x] = y;
		if(h[x]==h[y]) h[y]++;
	}
}

int main()
{
	int tc;
	scanf("%d",&tc);
	bool first = true;
	while(tc--)
	{
		if(first==false) printf("\n");
		first = false;
		int n;
		scanf("%d",&n);
		for(int a=0;a<n;a++)
		{
			scanf("%lf %lf",&p[a].x,&p[a].y);
			par[a] = a;
			h[a] = 1;
		}
		int k = 0;
		for(int a=0;a<n;a++)
		{
			for(int b=a+1;b<n;b++)
			{
				if(a!=b) pq.push(mp(-dist(a,b),mp(a,b))); 
			}
		}
		double ans = 0;
		while(!pq.empty())
		{
			double dd = -pq.top().ff;
			int t = pq.top().ss.ff;
			int s = pq.top().ss.ss;
			pq.pop();
			if(!issame(t,s))
			{
				join(t,s);
				ans+=dd;
			}
		}
		printf("%.2lf\n",ans);
	}
}
