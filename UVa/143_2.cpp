#include<bits/stdc++.h>
using namespace std;


struct Point{
	double x,y;
}p[5],hull[5];

double EPS = 1e-9;

double cross(Point a,Point b,Point c)
{
	return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}

bool check(Point a,Point b,Point c)
{
	if(min(b.x,c.x) <= a.x && max(b.x,c.x) >= a.x && min(b.y,c.y) <= a.y && max(b.y,c.y) >= a.y) return true;
	return false;
}

double sqr(double x)
{
	return x*x;
}

double dist(Point a,Point b)
{
	return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
}

double Triangle(Point a,Point b,Point c)
{
	double area = (a.x *b.y + b.x *c.y + c.x *a.y) - (a.y*b.x + b.y*c.x + c.y*a.x);
	if(area < 0) area*=-1;
	return area/2.0;
}

bool isinside(int aa,int bb)
{
	Point tp ;
	tp.x = aa;
	tp.y = bb;
	double area = Triangle(p[0],p[1],p[2]);
	double ww = 0;
	for(int a=0;a<3;a++) ww += Triangle(tp,p[a],p[(a+1)%3]);
	if(ww <= area + EPS) return true;
	return false;
}

bool cmp(Point a,Point b)
{
	if(a.x == b.x) return a.y < b.y;
	return a.x < b.x;
}

void CHULL()
{
	sort(p,p+3,cmp);
	if(cross(p[0],p[1],p[2]) == 0)
	{
		for(int a=0;a<3;a++) hull[a] = p[a];
		return ;
	}
	int k = 0;
	for(int a=0;a<3;a++)
	{
		while(k>=2 && cross(hull[k-2],hull[k-1],p[a]) <= 0) k--;
		hull[k++] = p[a];
	}
	int t = k+1;
	for(int a=1;a>=0;a--)
	{
		while(k>=t && cross(hull[k-2],hull[k-1],p[a]) <= 0) k--;
		hull[k++] = p[a];
	}
	k--;
}

int main()
{
	while(1)
	{
		double addw = 0;
		double miniy = 100;
		double maxiy = 0;
		double minix = 100;
		double maxix = 0;
		for(int a=0;a<3;a++) 
		{
			scanf("%lf %lf",&p[a].x,&p[a].y);
			minix = min(minix,p[a].x);
			maxix = max(maxix,p[a].x);
			miniy = min(miniy,p[a].y);
			maxiy = max(maxiy,p[a].y);
			addw += p[a].x + p[a].y;
		}
		if(addw == 0 )break;
		CHULL();
		for(int a=0;a<3;a++) p[a] = hull[a];
		int tot = 0;
		if(minix > (int) minix) minix++;
		if(miniy > (int) miniy) miniy++;
		minix = max((int) minix,1);
		miniy = max((int) miniy,1);
		maxix = min((int) maxix,99);
		maxiy = min((int) maxiy,99);
		for(int a=(int)minix;a<=maxix;a++)
		{
			for(int b=(int)miniy;b<=maxiy;b++)
			{
				if(isinside(a,b)==true) tot++;
			}
		}
		printf("%4d\n",tot);
	}
}
