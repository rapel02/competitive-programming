#include<bits/stdc++.h>
#define pi acos(-1)
using namespace std;

struct Point{
	double x,y;
}p[3];

double sqr(double a)
{
	return a*a;
}

double dist(Point a,Point b)
{
	return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
}

double d[3];

int main()
{
	while(scanf("%lf %lf",&p[0].x,&p[0].y)!=EOF)
	{
		for(int a=1;a<3;a++) scanf("%lf %lf",&p[a].x,&p[a].y);
		int k = 0;
		for(int a=0;a<3;a++)
		{
			for(int b=a+1;b<3;b++)
				d[k++] = dist(p[a],p[b]);
		}
		double s = (d[0]+d[1]+d[2])/2;
		double L = sqrt(s * (s-d[0]) * (s-d[1]) * (s-d[2]));
		double peri = d[0]*d[1]*d[2] *pi/ (2*L);
		printf("%.2lf\n",peri);
	}
}
