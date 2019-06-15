#include<bits/stdc++.h>
using namespace std;


struct Point{
	double x,y;
}temp,t[5],hull[5];

struct Shape{
	string type;
	double r;
	Point ctr;
	Point ll,rr;
	Point pt[3];
}p[150];

string in;

bool cmp(Point a,Point b){
	if(a.x < b.x) return true;
	if(a.x == b.x) return a.y < b.y;
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

bool PointInsideRectangle(Point a,Shape b)
{
	if(b.ll.x < a.x && a.x < b.rr.x && b.rr.y < a.y && a.y < b.ll.y) return true;
	return false;
}


double cross(Point a,Point b,Point c)
{
	return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

bool isMiddle(Point a,Point b,Point c)
{
	if(min(a.x,b.x) <= c.x && c.x <= max(a.x,b.x) && min(a.y,b.y) <= c.y && c.y <= max(a.y,b.y)) return true;
	return false; 
}

bool isInside(Point A,Shape B)
{
	for(int a=0;a<3;a++)
	{
		if(cross(A,B.pt[a],B.pt[(a+1)%3]) <= 0) return false;
		if(cross(A,B.pt[a],B.pt[(a+1)%3]) == 0)
		{
			if(isMiddle(B.pt[a],B.pt[(a+1)%3],A) == false) return false;
		}
	}
	return true;
}

int main()
{
	int k = 0;
	while(cin>>in)
	{
		if(in=="*") break;
		p[k].type = in;
		if(in=="c")
		{
			cin>>p[k].ctr.x>>p[k].ctr.y>>p[k].r;
		}
		else if(in=="r")
		{
			cin>>p[k].ll.x>>p[k].ll.y>>p[k].rr.x>>p[k].rr.y;
		}
		else
		{
			cin>>t[0].x>>t[0].y>>t[1].x>>t[1].y>>t[2].x>>t[2].y;
			sort(t,t+3,cmp);
			int c = 0;
			for(int a=0;a<3;a++)
			{
				while(c>=2 && cross(hull[c-2],hull[c-1],t[a]) < 0) c--;
				hull[c++] = t[a];
			}
			int tc = c;
			for(int a=1;a>=0;a--)
			{
				while(c>=tc && cross(hull[c-2],hull[c-1],t[a]) < 0) c--;
				hull[c++] = t[a];
			}
			c--;
			for(int a=0;a<3;a++) p[k].pt[a] = hull[a];
		}
		k++;
	}
	int tc = 0;
	while(1)
	{
		tc++;
		cin>>temp.x>>temp.y;
		if(temp.x == 9999.9 && temp.y == 9999.9) break;
		bool isfound = false;
		for(int a=0;a<k;a++)
		{
			if(p[a].type=="c")
			{
				if(dist(temp,p[a].ctr) < p[a].r)
				{
					isfound = true;
					printf("Point %d is contained in figure %d\n",tc,a+1);
				}
			}
			else if(p[a].type == "r")
			{
				if(PointInsideRectangle(temp,p[a]) == true) 
				{
					isfound = true;
					printf("Point %d is contained in figure %d\n",tc,a+1);
				}
			}
			else
			{
				if(isInside(temp,p[a]) == true)
				{
					isfound = true;
					printf("Point %d is contained in figure %d\n",tc,a+1);
				}
			}
		}
		if(isfound == false) printf("Point %d is not contained in any figure\n",tc);
	}
}
