#include<bits/stdc++.h>
using namespace std;

struct point{
	double x,y;
}p[5];

struct line{
	double a,b,c;
}l[2];


void pointsToLine(point p1,point p2,line &l)
{
	if(p1.x == p2.x)
	{
		l.a = 1.0;
		l.b = 0.0;
		l.c = -p1.x;
	}
	else
	{
		l.a = -(double) (p1.y - p2.y) / (p1.x - p2.x);
		l.b = 1.0;
		l.c = -(double) (l.a * p1.x) - p1.y;
	}
}

bool areParallel(line l1,line l2)
{
	if(l1.a == l2.a && l1.b == l2.b) return true;
	return false;
}

bool areSame(line l1,line l2)
{
	if(areParallel(l1,l2) && l1.c == l2.c) return true;
	return false;
}

point areIntersect(line l1,line l2)
{
	point p;
	p .x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
	if(l1.b != 0) p.y = -(l1.a * p.x + l1.c);
	else p.y = -(l2.a * p.x + l2.c);
	return p;
}

int main()
{
	int tc;
	scanf("%d",&tc);
	printf("INTERSECTING LINES OUTPUT\n");
	while(tc--)
	{
		for(int a=0;a<4;a++) cin>>p[a].x>>p[a].y;
		for(int a=0;a<2;a++) pointsToLine(p[2*a],p[2*a + 1],l[a]);
		if(areParallel(l[0],l[1]))
		{
			if(areSame(l[0],l[1])) printf("LINE\n");
			else printf("NONE\n");
		}
		else
		{
			point temp = areIntersect(l[0],l[1]);
			printf("POINT %.2lf %.2lf\n",temp.x,temp.y);
		}
	}
	printf("END OF OUTPUT\n");
}
