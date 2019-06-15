#include<bits/stdc++.h>
using namespace std;

struct point{
	double x,y;
	point()
	{
		x = y = 0.0;
	}
	point(double _x,double _y): x(_x),y(_y){}
};

vector<point> p,hull;

int k = 0;

struct shape{
	vector<point> v;
	int mark;
}sh[150];

int n;

bool cmp(point a,point b)
{
	if(a.x != b.x) return a.x < b.x;
	return a.y < b.y;
}

double cross(point a,point b,point c)
{
	return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

void CHULL()
{
	sort(p.begin(),p.end(),cmp);
	k = 0;
	for(int a=0;a<n;a++)
	{
		while(k>=2 && cross(hull[k-2],hull[k-1],p[a]) < 0) hull.pop_back(),k--;
		hull.push_back(p[a]),k++;
	}
	int t = k+1;
	for(int a=n-2;a>=0;a--)
	{
		while(k>=t && cross(hull[k-2],hull[k-1],p[a]) < 0) hull.pop_back(),k--;
		hull.push_back(p[a]),k++;
	}
	hull.pop_back();
}

double shoelace(point a,point b)
{
	return a.x * b.y - a.y * b.x;
}

double area(vector<point> P)
{
	int sz = P.size();
	double tot = 0;
	for(int a=0;a<sz;a++) tot += shoelace(P[a],P[(a+1)%sz]);
	return fabs(tot)/2.0;
}

bool isMiddle(point a,point b,point c)
{
	if(min(b.x,c.x) <= a.x && max(b.x,c.x) >= a.x && min(b.y,c.y) <= a.y && max(b.y,c.y) >= a.y) return true;
	return false;
}

bool isInside(point tp,vector<point> P)
{
	int sz = P.size();
	for(int a=0;a<sz;a++)
	{
		double cs = cross(tp,P[a],P[(a+1)%sz]);
		if(cs < 0) return false;
		if(cs == 0 && isMiddle(tp,P[a],P[(a+1)%sz]) == false) return false;
	}
	return true;
}

int main()
{
	int idx = 0;
	while(scanf("%d",&n)!=EOF)
	{
		if(n == -1) break;
		sh[idx].mark = 0;
		sh[idx].v.clear();
		p.clear();
		hull.clear();
		for(int a=0;a<n;a++)
		{
			double x,y;
			scanf("%lf %lf",&x,&y);
			p.push_back(point(x,y));
		}
		CHULL();
		sh[idx].v = hull;
		idx++;
	}
	point tp;
	double tot = 0;
	while(scanf("%lf %lf",&tp.x,&tp.y)!=EOF)
	{
		for(int a=0;a<idx;a++)
		{
			if(sh[a].mark == 1) continue;
			if(isInside(tp,sh[a].v) ) tot += area(sh[a].v), sh[a].mark = 1;
		}
	}
	printf("%.2lf\n",tot);
}
