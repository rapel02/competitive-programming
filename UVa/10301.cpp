#include<bits/stdc++.h>
using namespace std;

int par[150],h[150];

struct point{
	double x,y,r;
}p[150];

int find(int a)
{
	if(a == par[a]) return a;
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
	if(x > y)
	{
		par[x] = y;
		h[y] += h[x];
	}
	else
	{
		par[y] = x;
		h[x] += h[y];
	}
}

double sqr(double x)
{
	return x*x;
}

double dist(point a,point b)
{
	return sqrt(sqr(a.x - b.x) + sqr(a.y- b.y) );
}

int main()
{
	int n;
	while(cin>>n)
	{
		if(n==-1) break;
		for(int a=1;a<=n;a++) par[a] = a,h[a] = 1;
		for(int a=1;a<=n;a++) cin>>p[a].x>>p[a].y>>p[a].r;
		for(int a=1;a<=n;a++)
		{
			for(int b=1;b<=n;b++)
			{
				if(a==b) continue;
				double d = dist(p[a],p[b]);
				if(d < p[a].r + p[b].r && d >= fabs(p[a].r - p[b].r))
				{
					if(!issame(a,b)) disjoint(a,b);
				}
			}
		}
		int maxi = 0;
		for(int a=1;a<=n;a++) maxi = max(maxi,h[find(a)]);
		printf("The largest component contains %d ring%s.\n",maxi,(maxi==1)?"":"s");
	}
}
