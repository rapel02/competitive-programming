#include<bits/stdc++.h>
using namespace std;

struct Point{
	long double x,y;
}p[150];

const long double EPS = 1e-9;

long double dabs(long double x)
{
	if(x > -EPS) return x;
	return -x;
}

long double sqr(long double x)
{
	return x*x;
}

long double dist(Point a,Point b)
{
	return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
}

long double Posy(Point a,Point b,long double x)
{
	long double v1 = (x - b.x) / (a.x - b.x);
	long double diff = a.y - b.y;
	return v1 * diff + b.y;
}

int main()
{
	int ntc;
	scanf("%d",&ntc);
	for(int tc=1;tc<=ntc;tc++)
	{
		int k,t;
		scanf("%d %d",&k,&t);
		for(int a=0;a<k;a++) cin>>p[a].x>>p[a].y;
		long double len = 0;
		for(int a=0;a<k-1;a++) len += dist(p[a],p[(a+1)]);
		long double dt = len/(t-1);
		printf("Road #%d:\n",tc);
		printf("%.2Lf %.2Lf\n",p[0].x,p[0].y);
		Point last = p[0];
		int idx = 0;
		for(int a=1;a<t;a++)
		{
			long double tot = 0;
			while(tot < dt)
			{
				if(tot + dist(last,p[idx+1]) < dt)
				{
					tot += dist(last,p[idx+1]);
					last = p[idx+1];
					idx++;
					continue;
				}
				else
				{ 
					Point temp;
					Point rem;
					int revv = 0;
					int MAXN = 400;
					if(last.x != p[idx+1].x)
					{
						long double lo = min(last.x , p[idx+1].x);
						long double hi = max(last.x , p[idx+1].x);
						if(lo != last.x ) revv = 1;
						while(hi - lo > 1e-3)
						{
							long double mid = (lo + hi)/2.0;
							long double tar = Posy(last,p[idx+1],mid);
							temp.x = mid;
							temp.y = tar;
							if(tot + dist(last,temp) <= dt)
							{
								rem = temp;
								if(revv==0) lo = mid;
								else hi = mid;
							}
							else 
							{
								if(revv==0) hi = mid;
								else lo = mid;
							}
						}
						tot += dist(last,temp);
					}
					else
					{
						long double lo = min(last.y , p[idx+1].y);
						long double hi = max(last.y , p[idx+1].y);
						if(lo != last.y) revv = 1;
						while(hi - lo > 1e-3)
						{
							long double mid = (lo + hi)/2.0;
							temp.x = last.x;
							temp.y = mid;
							if(tot + dist(last,temp) <= dt) 
							{
								rem = temp;
								if(revv == 0)lo = mid;
								else hi = mid;
							}
							else
							{
								if(revv == 0) hi = mid;
								else lo = mid;
							}
						}
						tot += dist(last,rem);
					}
					last = rem;
				}
			}
			printf("%.2Lf %.2Lf\n",last.x,last.y);
		}
		printf("\n");
	}
}
