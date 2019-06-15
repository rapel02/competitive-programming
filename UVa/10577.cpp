#include<bits/stdc++.h>
using namespace std;

struct point{
	double x,y;
}p[5];

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
	return acos((sqr(a) + sqr(b) - sqr(c)) / (2.0 * a * b));
}

double circleOutTriangle(point a,point b,point c)
{
	double AB = dist(a,b);
	double AC = dist(a,c);
	double BC = dist(b,c);
	double theta = angle(AB,AC,BC);
	double s = (AB + AC + BC) / 2.0;
	double L = sqrt(s * (s-AB) * (s-AC) * (s-BC));
	return (AB * AC * BC) / (4 * L);
}

int circleRad(point p1,point p2,point &c,double r)
{
	double d2 = sqr(p1.x - p2.x) + sqr(p1.y - p2.y);
	double det = r *r/ d2 - 0.25;
	double h = sqrt(det);
	int t1 = 0;
	c.x = (p1.x + p2.x) * 0.5 + (p1.y - p2.y) * h;
	c.y = (p1.y + p2.y) * 0.5 + (p2.x - p1.x) * h;
	for(int a=0;a<3;a++) if(dist(p[a],c) -r <= EPS) t1++;
	return t1;
}

point rotate(point a,point o,double deg)
{
	a.x -= o.x;
	a.y -= o.y;
	point ans;
	ans.x = cos(deg) * a.x - sin(deg) * a.y;
	ans.y = sin(deg) * a.x + cos(deg) * a.y;
	ans.x += o.x;
	ans.y += o.y;
	return ans;
}

int main()
{
	int n;
	int tc = 0;
	while(scanf("%d",&n),n)
	{
		tc++;
		for(int a=0;a<3;a++) scanf("%lf %lf",&p[a].x,&p[a].y);
		double r = circleOutTriangle(p[0],p[1],p[2]);
		point cen;
		for(int a=0;a<3;a++)
		{
			for(int b=0;b<3;b++)
			{
				point c;
				if(circleRad(p[a],p[b],c,r) == 3) cen = c;
			}
		}
		//printf("%lf %lf\n",cen.x,cen.y);
		double xmax,xmin,ymax,ymin;
		xmax = xmin = p[0].x;
		ymax = ymin = p[0].y;
		double add = 2*PI / (1.0 * n);
		double ang = 0;
		for(int a=0;a<n;a++)
		{
			point pos = rotate(p[0],cen,ang);
			xmax = max(xmax,pos.x);
			xmin = min(xmin,pos.x);
			ymax = max(ymax,pos.y);
			ymin = min(ymin,pos.y);
			ang+=add;
		}
		printf("Polygon %d: %.3lf\n",tc,(xmax - xmin) * (ymax - ymin));
	}
}
