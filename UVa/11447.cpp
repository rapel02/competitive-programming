#include<bits/stdc++.h>
using namespace std;

struct Point{
	double x,y;
}p[15000];

const double EPS = 1e-9;

double shoelace(Point a,Point b)
{
	return a.x * b.y - a.y * b.x;
}

double dabs(double x)
{
	if(x > -EPS) return x;
	return -x;
}

int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		int n;
		scanf("%d",&n);
		for(int a=0;a<n;a++) cin>>p[a].x>>p[a].y;
		double area = 0;
		for(int a=0;a<n;a++) area += shoelace(p[a],p[(a+1)%n]);
		area = dabs(area)/2.0;
		double w;
		cin>>w;
		double v = area * w;
		double rem = v;
		double per,p1,p2;
		cin>>per>>p1>>p2;
		v = v * per/100.0;
		v -= p1;
		if(v < 0) 
		{
			printf("Lack of water. ");
			v = 0;
		}
		v +=p2;
		if(v > rem)
		{
			printf("Excess of water. ");
			v = rem;
		}
		printf("Final percentage: %d%\n",(int)(v*100/rem) );
	}
}
