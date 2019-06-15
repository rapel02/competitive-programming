#include<bits/stdc++.h>
using namespace std;

struct point{
	double x,y;
	double d,s;
	double cc,ss;
}p[1005];

const double PI = acos(-1);

double toRad(double x)
{
	return x * PI / 180.0;
}

int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		int n;
		double r;
		scanf("%d %lf",&n,&r);
		r*=r;
		for(int a=0;a<n;a++)
		{
			scanf("%lf %lf %lf %lf",&p[a].x,&p[a].y,&p[a].d,&p[a].s);
			p[a].d = (90.0 - p[a].d);
			p[a].d = toRad(p[a].d);
			p[a].cc = cos(p[a].d);
			p[a].ss = sin(p[a].d);
		}
		double ans = 1e+16;
		for(int a=0;a<n;a++)
		{
			for(int b=a+1;b<n;b++)
			{
				double A,B,C;
				double x1 = (p[a].s) * p[a].cc;
				double y1 = (p[a].s) * p[a].ss;
				double x2 = (p[b].s) * p[b].cc;
				double y2 = (p[b].s) * p[b].ss;
				double dx1 = p[a].x - p[b].x;
				double dx2 = x1 - x2;
				double dy1 = p[a].y - p[b].y;
				double dy2 = y1 - y2;
				A = dx2*dx2 + dy2*dy2;
				B = 2*dx1*dx2 + 2*dy1*dy2;
				C = dx1*dx1 + dy1*dy1;
				double Aa,Bb;
				Aa = 2 * A;
				Bb = B;
				if(Aa == 0)
				{
					double di = (C);
					if(di <= r) ans = 0;
					continue;
				}
				double lo = 0;
				double hi = -Bb/Aa;
				if(hi < 0)
				{
					double di = (C);
					if(di <= r) ans = 0;
					continue;
				}
				double di = ((A*hi*hi + B*hi + C) );
				if(di > r) continue;
				for(int c=0;c<30;c++)
				{
					double mid = (lo + hi)/2.0;
					double di = ((A*mid*mid + B*mid + C) );
					if(di <= r) hi = mid;
					else lo = mid;
				}
				ans = min(ans,hi);
			}
		}
		if(ans!=1e+16) printf("%.0lf\n",ans);
		else printf("No collision.\n");
	}
}
