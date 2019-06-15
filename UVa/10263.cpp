#include<bits/stdc++.h>
using namespace std;

struct Point{
	double x,y;
	Point(){
		x = y = 0.0;
	}
	Point(double _x,double _y): x(_x),y(_y){}
}tar,p[1500000];

struct vec{
	double x,y;
	vec(double _x,double _y): x(_x),y(_y){}
};

vec toVec(Point a,Point b){
	return vec(b.x - a.x,b.y - a.y);
}

vec scale(vec v,double s)
{
	return vec(v.x * s, v.y * s);
}

Point translate(Point p,vec v)
{
	return Point(p.x + v.x, p.y + v.y);
}

double dot(vec a,vec b)
{
	return (a.x * b.x + a.y * b.y);
}

double dist(Point a,Point b)
{
	return hypot(a.x - b.x,a.y - b.y);
}

double norm_sqr(vec a)
{
	return a.x *a.x + a.y * a.y;
}

double distToLine(Point p,Point a,Point b,Point &c)
{
	vec ap = toVec(a,p);
	vec ab = toVec(a,b);
	double u = dot(ap,ab) / norm_sqr(ab);
	if(u < 0.0)
	{
		c = Point(a.x,a.y);
		return dist(p,a);
	}
	if(u > 1.0)
	{
		c = Point(b.x,b.y);
		return dist(p,b);
	}
	c = translate(a,scale(ab,u));
	double d = dist(tar,c);
}

int main()
{
	while(cin>>tar.x>>tar.y)
	{
		int n;
		scanf("%d",&n);
		double maxx = 1e+12;
		Point ans;
		for(int a=0;a<n+1;a++)
		{
			cin>>p[a].x>>p[a].y;
			if(a > 0)
			{
				Point c;
				double d = distToLine(tar,p[a],p[a-1],c);
				if(d < maxx)
				{
					maxx = d;
					ans = c;
				}
			}
		}
		printf("%.4lf\n%.4lf\n",ans.x,ans.y);
	}
}
