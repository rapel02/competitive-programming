#include<bits/stdc++.h>
using namespace std;

struct point{
	double x,y;
	point(){x = y = 0.0;}
	point(double _x,double _y): x(_x),y(_y){}
	bool operator == (point other) const{
	return x == other.x && y == other.y;}
};

const double EPS = 1e-9;

struct vec{
	double x,y;
	vec(){x = y = 0.0;}
	vec(double _x,double _y): x(_x),y(_y){}
};

vec toVec(point a,point b)
{
	return vec(b.x - a.x,b.y - a.y);
}

double cross(vec a,vec b)
{
	return a.x * b.y - a.y * b.x; 
}

point lineIntersectSeg(point p,point q,point A,point B)
{
	double a = B.y - A.y;
	double b = A.x - B.x;
	double c = B.x * A.y - A.x * B.y;
	double u = fabs(a * p.x + b * p.y + c);
	double v = fabs(a * q.x + b * q.y + c);
	return point((p.x * v + q.x * u) / (u + v) , (p.y * v + q.y * u) / (u + v));
}

vector<point> cutPolygon(point a,point b,const vector<point> &Q)
{
	vector<point> P;
	for(int i=0;i<(int)Q.size();i++)
	{
		double left1 = cross(toVec(a,b), toVec(a,Q[i])), left2 = 0;
		if(i != (int)Q.size() - 1) left2 = cross(toVec(a,b),toVec(a,Q[i+1]));
		if(left1 > -EPS) P.push_back(Q[i]);
		if(left1 * left2 < -EPS) P.push_back(lineIntersectSeg(Q[i],Q[i+1],a,b));
	}
	if(!P.empty() && !(P.back() == P.front())) P.push_back(P.front());
	return P;
}

double shoelace(point a,point b)
{
	return a.x * b.y - a.y * b.x;
}

double area(vector<point> P)
{
	int sz = P.size();
	double ar = 0;
	for(int a=0;a<sz;a++) ar += shoelace(P[a],P[(a+1)%sz]);
	return fabs(ar)/2.0;
}

int main()
{
	int tc = 0;
	double W,H,x,y;
	int N;
	vector<point> p;
	while(scanf("%d %lf %lf %lf %lf",&N,&W,&H,&x,&y)!=EOF)
	{
		p.clear();
		p.push_back(point(0,0));
		p.push_back(point(W,0));
		p.push_back(point(W,H));
		p.push_back(point(0,H));
		p.push_back(point(0,0));
		point ctr(x,y);
		tc++;
		for(int a=0;a<N;a++)
		{
			point p1,p2;
			scanf("%lf %lf %lf %lf",&p1.x,&p1.y,&p2.x,&p2.y);
			if(cross(toVec(p1,p2), toVec(p1,ctr)) > 0) p = cutPolygon(p1,p2,p);
			else p = cutPolygon(p2,p1,p);
		}
		printf("Case #%d: %.3lf\n",tc,area(p));
	}
}
