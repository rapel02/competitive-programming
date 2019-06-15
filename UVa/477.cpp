#include<bits/stdc++.h>
using namespace std;


struct Point{
	double x,y;
}temp;

struct Shape{
	string type;
	double r;
	Point ctr;
	Point ll,rr;
}p[150];

string in;

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
	if(b.ll.x <= a.x && a.x <= b.rr.x && b.rr.y <= a.y && a.y <= b.ll.y) return true;
	return false;
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
		else
		{
			cin>>p[k].ll.x>>p[k].ll.y>>p[k].rr.x>>p[k].rr.y;
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
				if(dist(temp,p[a].ctr) <= p[a].r)
				{
					isfound = true;
					printf("Point %d is contained in figure %d\n",tc,a+1);
				}
			}
			else
			{
				if(PointInsideRectangle(temp,p[a]) == true) 
				{
					isfound = true;
					printf("Point %d is contained in figure %d\n",tc,a+1);
				}
			}
		}
		if(isfound == false) printf("Point %d is not contained in any figure\n",tc);
	}
}
