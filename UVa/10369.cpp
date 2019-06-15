#include<bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
using namespace std;

struct Point{
	double x,y;
}p[550];

int par[550],h[550];

priority_queue<pair<double,pair<int,int> > > pq;


int find(int a)
{
	if(a==par[a]) return a;
	return par[a] = find(par[a]);
}

bool issame(int a,int b)
{
	return find(a) == find(b);
}

void disjoint(int a,int b)
{
	int x = find(a);
	int y = find(b);
	if(h[x] > h[y]) par[y] = x;
	else par[x] = y, (h[x]==h[y])?h[y]++:h[y];
}

double sqr(double x)
{
	return x*x;
}

double dist(Point a,Point b)
{
	return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
}

int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int k,n;
		cin>>k>>n;
		int t = n;
		for(int a=0;a<n;a++) par[a] = a,h[a] = 1;
		for(int a=0;a<n;a++) cin>>p[a].x>>p[a].y;
		for(int a=0;a<n;a++)
		{
			for(int b=a+1;b<n;b++) pq.push(mp(-dist(p[a],p[b]),mp(a,b)));
		}
		double ans = 0;
		while(!pq.empty())
		{
			double val = -pq.top().ff;
			int x = pq.top().ss.ff;
			int y = pq.top().ss.ss;
			pq.pop();
			if(t!=k && !issame(x,y))
			{
				t--;
				disjoint(x,y);
				ans = max(ans,val);
			}
		}
		printf("%.2lf\n",ans);
	}
}
