#include<bits/stdc++.h>
#define mp make_pair
using namespace std;


struct point{
	double x,y;
}p[500];

int ans = 0;
int k = 0;

double sqr(double x)
{
	return x*x;
}

double dist(point a,point b)
{
	return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
}

const double EPS = 1e-9;
point c;
int circleRad(point p1,point p2)
{
	double d2 = sqr(p1.x - p2.x) + sqr(p1.y - p2.y);
	double det = 2.500000 * 2.500000/ d2 - 0.25;
	double h = sqrt(det);
	int t1 = 0;
	c.x = (p1.x + p2.x) * 0.5 + (p1.y - p2.y) * h;
	c.y = (p1.y + p2.y) * 0.5 + (p2.x - p1.x) * h;
	for(int a=0;a<k;a++) if(dist(p[a],c) - 2.5<= EPS) t1++;
	return t1;
}

map<pair<double,double>,int> mmap;

int main()
{
	int n;
	scanf("%d",&n);
	getchar();
	getchar();
	bool isf = true;
	while(n--)
	{
		mmap.clear();
		if(!isf) printf("\n");
		isf = false;
		string in;
		k = 0;
		while(getline(cin,in))
		{
			if(in.length() == 0) break;
			stringstream s(in);
			s>>p[k].x>>p[k].y;
			bool iss = false;
			//if(mmap[mp(p[k].x,p[k].y)]==1) iss = true;
			mmap[mp(p[k].x,p[k].y)] = 1;
			if(iss==false) k++;
		}
		ans = min(1,k);
		for(int a=0;a<k;a++)
		{
			for(int b=0;b<k;b++)
			{
				if(dist(p[a],p[b]) -5.0 <= EPS) 
				{
					int v1 = circleRad(p[a],p[b]);
					ans = max(ans,v1);
				}
			}
		}
		printf("%d\n",ans);
	}
}
