#include<bits/stdc++.h>
using namespace std;

struct Point{
	long double x,y;
}p[150],hull[140];

int k = 0,n;

bool cmp(Point a,Point b)
{
	if(a.x < b.x) return true;
	if(a.x == b.x) return a.y < b.y;
	return false;
}

long double cross(Point a,Point b,Point c)
{
	return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

void CHULL()
{
	k = 0;
	for(int a=0;a<n;a++)
	{
		while(k>=2 && cross(hull[k-2],hull[k-1],p[a]) <=0 ) k--;
		hull[k++] = p[a];
	}
	int t = k+1;
	for(int a=n-2;a>=0;a--)
	{
		while(k>=t && cross(hull[k-2],hull[k-1],p[a]) <=0) k--;
		hull[k++] = p[a];
	}
	k--;
}

long double sqr(long double x)
{
	return x*x;
}

long double dist(Point a,Point b)
{
	return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
}

long double calc(Point a,Point b,Point c)
{
	long double p1 = 0,p2 = 0;
	p1 = a.x*b.y + b.x*c.y + c.x*a.y;
	p2 = (a.y*b.x + b.y*c.x + c.y*a.x);
	return (fabs(p1 - p2)/2);
}

int main()
{
	int tc = 0;
	while(scanf("%d",&n),n)
	{
		tc++;
		for(int a=0;a<n;a++) cin>>p[a].x>>p[a].y;
		sort(p,p+n,cmp);
		CHULL();
		for(int a=0;a<k;a++) p[a] = hull[a];
		long double ans = 1e+15;
		for(int a=0;a<k;a++)
		{
			long double temp = 0;
			long double le = dist(p[a],p[(a+1)%k]);
			for(int b=0;b<k;b++)
			{
				long double area = calc(p[a],p[(a+1)%k],p[b]);
				long double x = 2*area / le;
				temp = max(temp,x);
			}
			ans = min(ans,temp);
		}
		printf("Case %d: %.2Lf\n",tc,ans+0.00999999);
	}
}
