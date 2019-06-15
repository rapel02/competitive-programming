#include<bits/stdc++.h>
#define EPS 1e-9
using namespace std;

struct Point{
	double x,y;
}p[500];

double r;
int n;

double sqr(double a)
{
	return a*a;
}

double dist(Point a,Point b)
{
	return sqrt(sqr(a.x - b.x) + sqr(a.y -b.y));
}

bool circle_mid(Point a,Point b,int num)
{
	Point temp;
	if(num==1)
	{
		temp.x = (2*a.x + b.x)/3;
		temp.y = (2*a.y + b.y)/3;
		bool ada = true;
		for(int aa=1;aa<=n;aa++)
		{
			if(dist(p[aa],temp)-r>-EPS) return false;
		}
		return true;
	}
	else if(num==0)
	{
		temp.x = (a.x + b.x)/2;
		temp.y = (a.y + b.y)/2;
		bool ada = false;
		for(int aa=1;aa<=n;aa++)
		{
			if(circle_mid(temp,p[aa],num+1)==true) return true;
		}
		return false;
	}
}

int main()
{
	while(1)
	{
		scanf("%d",&n);
		if(n==0) break;
		for(int a=1;a<=n;a++)
			scanf("%lf %lf",&p[a].x, &p[a].y);
		scanf("%lf",&r);
		bool ada = false;
		for(int a=1;a<=n;a++)
		{
			for(int b=1;b<=n;b++)
				if(circle_mid(p[a],p[b],0)==true) ada = true;
		}
		if(ada==true) printf("The polygon can be packed in the circle.\n");
		else printf("There is no way of packing that polygon.\n");
	}
}
