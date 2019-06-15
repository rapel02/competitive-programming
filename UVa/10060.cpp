#include<bits/stdc++.h>
using namespace std;

struct Point{
	double x,y;
}p[150000];

const double PI = acos(-1);

double shoelace(Point a,Point b)
{
	return a.x*b.y - a.y*b.x;
}

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		double tot = 0;
		if(n==0) break;
		for(int a=0;a<n;a++)
		{
			int idx = 1;
			double h;
			scanf("%lf",&h);
			scanf("%lf %lf",&p[0].x,&p[0].y);
			while(1)
			{
				scanf("%lf %lf",&p[idx].x,&p[idx].y);
				if(p[idx].x == p[0].x && p[idx].y == p[0].y) break;
				idx++;
			}
			double tmp = 0;
			for(int a=0;a<idx;a++)
			{
				tmp = tmp + shoelace(p[a],p[(a+1)%idx]);
			}
			tmp/=2.0;
			tmp = fabs(tmp);
			tot = tot + tmp * h;
		}
		double r,t;
		scanf("%lf %lf",&r,&t);
		double V = PI*r*r*t;
		printf("%lld\n",(long long)floor(tot/V));
	}
}
