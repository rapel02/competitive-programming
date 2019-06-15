#include<bits/stdc++.h>
using namespace std;

struct point{
	double x,y;
	double l;
	double r,g,b;
	string s;
}p[150];

int stt = -1;

double sqr(double x)
{
	return x*x;
}

double dist(point p,double x,double y)
{
	return (sqr(p.x - x) + sqr(p.y - y));
}

bool isMiddle(point p,double x,double y)
{
	if(p.x <= x && x <= p.x + p.l && p.y <= y && y <= p.y + p.l) return true;
	return false;
}

bool check(point p,double x,double y)
{
	bool ist = false;
	if(p.s == "CIRCLE")
	{
		double d = dist(p,x,y);
		if(d<=p.l * p.l) ist = true,stt = max(stt,0);
		if(d == p.l * p.l) stt = 1;
	}
	else
	{
		if(isMiddle(p,x,y))
		{
			ist = true;
			stt = max(stt,0);
			if(p.x == x || p.x + p.l == x || p.y == y || p.y + p.l == y) stt = 1;
		}
	}
	return ist;
}

int main()
{
	ios_base::sync_with_stdio(false);
	int ntc;
	cin>>ntc;
	double px = 8.5;
	for(int tc=1;tc<=ntc;tc++)
	{
		if(tc!=1) printf("\n");
		int R,P;
		cin>>R>>P;
		for(int a=0;a<R;a++)
		{
			string s1;
			double x,y,l,r,g,b;
			cin>>s1>>x>>y>>l>>r>>g>>b;
			p[a].x = x;
			p[a].y = y;
			p[a].l = l;
			p[a].r = r;
			p[a].g = g;
			p[a].b = b;
			p[a].s = s1;
		}
		printf("Case %d:\n",tc);
		for(int a=0;a<P;a++)
		{
			double x,y;
			double tr = 0,tg = 0,tb = 0;
			double n = 0;
			cin>>x>>y;
			stt = -1;
			for(int b=0;b<R;b++)
			{
				if(check(p[b],x,y) == true)
				{
					tr += p[b].r;
					tg += p[b].g;
					tb += p[b].b;
					n  = n + 1;
				}
			}
			if(stt == -1) tr = 255,tg = 255, tb = 255, n = 1;
			if(stt == 1) tr = 0,tg = 0, tb = 0, n = 1;
			tr = round(tr/n);
			tg = round(tg/n);
			tb = round(tb/n);
			printf("(%d, %d, %d)\n",(int)tr,(int)tg,(int)tb);
		}
	}
}
