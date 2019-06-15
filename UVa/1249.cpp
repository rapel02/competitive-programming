#include<bits/stdc++.h>
using namespace std;


struct point{
	double x,y;
}p[15];

double shoelace(point a,point b)
{
	return(a.x * b.y - a.y * b.x);
}

double sqr(double x)
{
	return x*x;
}

double dist(point a,point b)
{
	return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
}

int main()
{
	while(1)
	{
		bool isz = true;
		for(int a=0;a<6;a++)
		{
			cin>>p[a].x>>p[a].y;
			if(p[a].x!=0 || p[a].y !=0) isz = false;
		}
		if(isz==true) break;
		double area = 0;
		for(int a=3;a<6;a++) area += shoelace(p[a],p[(a+1)==6?3:a+1]);
		area = fabs(area)/2.0;
		double area2 = 0;
		for(int a=0;a<3;a++) area2 += shoelace(p[a],p[(a+1)%3]);
		area2 = fabs(area2)/2.0;
		double AB = dist(p[0],p[1]);
		double AC = dist(p[0],p[2]);
		double sinA = 2*area2 / (AB*AC);
		double AH = area / (AB * sinA); 
		point h,g;
		h.x = p[0].x + (p[2].x - p[0].x) * AH / AC;
		h.y = p[0].y + (p[2].y - p[0].y) * AH / AC;
		g.x = (h.x - p[0].x) + p[1].x;
		g.y = (h.y - p[0].y) + p[1].y;
		printf("%.3lf %.3lf %.3lf %.3lf\n",g.x,g.y,h.x,h.y);
	}
}
