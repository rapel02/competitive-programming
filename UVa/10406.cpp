#include<bits/stdc++.h>
using namespace std;

struct point{
	double x,y;
}p[250000];

struct line{
	double a,b,c;
};

double X;
vector<point> pt,hull;
const double PI = acos(-1);
const double EPS = 1e-9;

void pointsToLine(point p1,point p2,line &l)
{
	double deg = atan2(p2.y-p1.y,p2.x-p1.x);
	deg -= PI/2.0;
	while(deg < 0) deg+=2*PI;
	double dx = cos(deg) * X;
	double dy = sin(deg) * X;
	p1.x += dx;
	p1.y += dy;
	p2.x += dx;
	p2.y += dy;
	//cout<<p1.x<<" "<<p1.y<<" "<<deg<<endl;
	if(fabs(p1.x - p2.x) < EPS) l.a = 1.0,l.b = 0.0,l.c = -p1.x;
	else
	{
		l.a = -(double) (p1.y - p2.y) / (p1.x - p2.x);
		l.b = 1.0;
		l.c = -(double) (l.a*p1.x) - p1.y;
	}
}

bool areIntersect(line l1,line l2,point &p)
{
	p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
	if(fabs(l1.b) > EPS) p.y = -(l1.a * p.x + l1.c);
	else p.y = -(l2.a * p.x + l2.c);
	return true; 
}

double shoelace(point a,point b)
{
	return a.x*b.y - a.y *b.x;
}

double cross(point a,point b,point c){
	return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

double CHULL()
{
	int k =0;
	double ans = 0;
	int sz = pt.size();
	for(int a=0;a<sz;a++) ans += shoelace(pt[a],pt[(a+1)%sz]);
	ans = fabs(ans);
	ans/=2.0;
	return ans;
}

int main()
{
	int n;
	while(cin>>X>>n)
	{
		pt.clear();
		hull.clear();
		if(X + n == 0) break;
		for(int a=0;a<n;a++) cin>>p[a].x>>p[a].y;
		double tans = 0;
		for(int a=0;a<n;a++) tans += shoelace(p[a],p[(a+1)%n]);
		tans = fabs(tans)/2.0;
		for(int a=0;a<n;a++)
		{
			line l1,l2;
			pointsToLine(p[a],p[(a+1)%n],l1);
			pointsToLine(p[(a+1)%n],p[(a+2)%n],l2);
			point tp;
			if(areIntersect(l1,l2,tp)) 
			{
				pt.push_back(tp);
			}
		}
		double ans = CHULL();
		printf("%.3lf\n",ans);
	}
}
