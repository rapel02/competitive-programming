#include<bits/stdc++.h>
using namespace std;


struct point{
	double x,y;
	point(){}
	point(double _x,double _y):x(_x),y(_y)
	{}
}p[3];

struct vec{
	double x,y;
	vec(){}
	vec(double _x,double _y): x(_x),y(_y)
	{}
};

vec toVec(point a,point b)
{
	return vec(b.x - a.x , b.y - a.y);
}

vec scale(vec v,double s)
{
	return vec(v.x * s,v.y * s);
}

point translate(point p, vec v)
{
	return point(p.x + v.x, p.y + v.y);
}

double r,theta;

const double PI = acos(-1);

const double EPS = 1e-9;
double sqr(double x)
{
	return x*x;
}

double dist(point a,point b)
{
	return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
}

double angle(double a,double b,double c)
{
	return acos((sqr(a) + sqr(b) - sqr(c))/(2.0 * a * b));
}

double dot(vec a,vec b)
{
	return a.x * b.x + a.y * b.y;
}

double norm_sq(vec v)
{
	return v.x * v.x + v.y * v.y; 
}

double distToLine(point p,point a,point b)
{
	vec ap = toVec(a,p), ab = toVec(a,b);
	double u = dot(ap,ab) / norm_sq(ab);
	if( u < -EPS)
	{
		return dist(p,a);
	}
	if(u - 1.0 > EPS)
	{
		return dist(p,b);
	}
	point c = translate(a,scale(ab,u));
	return dist(p,c);
}

double xmult(point p1,point p2,point p0)
{
	return (p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y);
}

double disptoline(point p,point l1,point l2)
{
	return fabs(xmult(p,l1,l2)) / dist(l1,l2);
}

int intersect_seg_circle(point c,double r,point l1,point l2)
{
	point t = c;
	t.x += l1.y - l2.y;
	t.y += l2.x - l1.x;
	return xmult(l1,c,t) * xmult(l2,c,t) < EPS && disptoline(c,l1,l2) < r;
}

int main()
{
	int n;
	while(cin>>n)
	while(n--)
	{
		p[0].x = p[0].y = 0;
		for(int a=1;a<=2;a++) cin>>p[a].x>>p[a].y;
		cin>>r;
		double l = distToLine(p[0],p[1],p[2]);
		if(!intersect_seg_circle(p[0],r,p[1],p[2]))
		{
			printf("%.3lf\n",dist(p[1],p[2]));
		}
		else
		{
			double AB = dist(p[0],p[1]);
			double AC = dist(p[0],p[2]);
			double BC = dist(p[1],p[2]);
			theta = angle(AB,AC,BC);
			double t1 = acos(r/AB);
			double t2 = acos(r/AC);
			double res = theta - t1 - t2;
			double V1 = sqrt(sqr(AB) - sqr(r));
			double V2 = sqrt(sqr(AC) - sqr(r));
			double arc = r * res;
			printf("%.3lf\n",V1 + V2 + arc);
		}
	}
}
