#include<bits/stdc++.h>
#define EPS 1e-9
using namespace std;

struct Point{
	double x,y;
}p[5];

double sqr(double a)
{
	return a*a;
}

double dist(Point a,Point b)
{
	return sqr(a.x - b.x) + sqr(a.y- b.y);
}

int main()
{
	int a1,a2,a3,a4;
	while(1)
	{
		scanf("%d %d %d %d",&a1,&a2,&a3,&a4);
		if(a1+a2+a3+a4==0) break;
		p[0].x = a3;
		p[0].y = a3;
		p[1].x = a1 - a4;
		p[1].y = a2 - a4;
		bool ans = true;
		if(a3*2>a1 || a3*2>a2) ans = false;
		if(a4*2>a1 || a4*2>a2) ans = false;
		if(dist(p[0],p[1]) - sqr(a3+a4) < -EPS) ans = false;
		printf("%c\n",ans?'S':'N');
	}
}
