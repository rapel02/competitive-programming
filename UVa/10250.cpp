#include<bits/stdc++.h>
using namespace std;

struct point{
	double x,y;
}p1,p2;

int main()
{
	while(cin>>p1.x>>p1.y>>p2.x>>p2.y)
	{
		point pm;
		pm.x = (p1.x + p2.x)/2.0;
		pm.y = (p1.y + p2.y)/2.0;
		double dx = (pm.x - p1.x);
		double dy = (pm.y - p1.y);
		printf("%lf %lf %lf %lf\n",pm.x + dy,pm.y - dx,pm.x - dy,pm.y + dx);
	}
}
