#include<bits/stdc++.h>
using namespace std;

const double EPS = 1e-12;
const double PI = acos(-1);
struct Point{
	double x,y;
}p[150000],t;

int n;

double dabs(double x)
{
	if(x < -EPS) return -x;
	return x;
}

double cross(Point a,Point b,Point c)
{
	return (b.x - a.x)*(c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

double sqr(double x)
{
	return x*x;
}

double dist(Point a,Point b)
{
	return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
}

double angle(Point a,Point b,Point c)
{
	double AC = dist(a,c);
	double AB = dist(a,b);
	double BC = dist(b,c);
	return acos( (sqr(AB) + sqr(BC) - sqr(AC)) / (2*AB*BC));
}

bool inPolygon()
{
	double tot = 0;
	for(int a=0;a<n;a++)
	{
		if(cross(t,p[a],p[(a+1)%n]) < 0) tot += angle(p[a],t,p[(a+1)%n]);
		else tot -= angle(p[a],t,p[(a+1)%n]);
	}
	return dabs(dabs(tot) - 2.0*PI) < EPS;
}

int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0) break;
		for(int a=0;a<n;a++) scanf("%lf %lf",&p[a].x,&p[a].y);
		scanf("%lf %lf",&t.x,&t.y);
		if(inPolygon()==true) printf("T\n");
		else printf("F\n");
	}
}
