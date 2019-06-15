#include<bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
using namespace std;

struct Point{
	double x,y;
}p[15000],tp;

map<double,int> mmap;

double sqr(double x)
{
	return x*x;
}

double dist(Point a,Point b)
{
	return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
}

bool cmp(Point a,Point b)
{
	if(a.x < b.x) return true;
	if(a.x == b.x) return a.y < b.y;
	return false;
}

int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n;
		cin>>n;
		mmap.clear();
		int err = 0;
		tp.x = 0;
		tp.y = 0;
		for(int a=0;a<n;a++) 
		{
			cin>>p[a].x>>p[a].y;
			tp.x += p[a].x;
			tp.y += p[a].y;
		}
		sort(p,p+n,cmp);
		bool isada = false;
		tp.x = (p[0].x + p[n-1].x)/2.0;
		tp.y = (p[0].y + p[n-1].y)/2.0;
		for(int a=0;a<n;a++)
		{
			if(tp.x != (p[a].x + p[n-1-a].x)/2.0 || tp.y != (p[a].y + p[n-1-a].y)/2.0 ) isada = true;
		}
		if(isada==false) printf("yes\n");
		else printf("no\n");
	}
}
