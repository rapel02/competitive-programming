#include<bits/stdc++.h>
#define EPS 1e-9
using namespace std;

struct Point{
	int x,y;
};

struct Line_Point{
	int x1,x2,y1,y2;
}p[100005];

struct Line{
	double a,b,c;
}l[100005];

double dabs(double x)
{
	if(x<-EPS) return -x;
	return x;
}

void PointstoLine(int k, Line_Point a)
{
	if(dabs(a.x2 - a.x1)<EPS)
	{
		l[k].a = 1.0;
		l[k].b = 0.0;
		l[k].c = -a.x1; 
	}
	else
	{
		l[k].a = -1.0 * (a.y1 - a.y2) / (a.x1 - a.x2);
		l[k].b = 1.0;
		l[k].c = -1.0*(l[k].a * a.x1) - a.y1;
	}
}

bool cmp(Line_Point a,Line_Point b)
{
	if(a.y2 > b.y2) return true;
	return false;
}

bool between(Line_Point a,Point b)
{
	if(a.x2<a.x1)
	{
		if (a.x1>=b.x &&a.x2<=b.x) return true;
		return false;
	}
	else
	{
		if(a.x2>=b.x && a.x1<=b.x) return true;
		return false;
	}
}

int main()
{
	int tc;
	bool first = true;
	scanf("%d",&tc);
	while(tc--)
	{
		int n;
		if(first==false) printf("\n");
		first = false;
		scanf("%d",&n);
		for(int a=0;a<n;a++)
		{
			scanf("%d %d %d %d",&p[a].x1,&p[a].y1,&p[a].x2,&p[a].y2);
			if(p[a].y1<p[a].y2)
			{
				swap(p[a].x1,p[a].x2);
				swap(p[a].y1,p[a].y2);
			}
		//	printf("%lf %lf %lf %lf\n",p[a].x1,p[a].y1,p[a].x2,p[a].y2);
		}
		sort(p,p+n,cmp);
		for(int a=0;a<n;a++)
		{
		//	printf("%d %d %d %d %d\n",a,p[a].x1,p[a].y1,p[a].x2,p[a].y2);
			PointstoLine(a,p[a]);
		}
		int tc;
		scanf("%d",&tc);
		for(int tcc=1;tcc<=tc;tcc++)
		{
			Point tp;
			scanf("%d %d",&tp.x,&tp.y);
			for(int a=0;a<n;a++)
			{
				if(tp.y == 0) break;
				if(tp.y < p[a].y2 ) continue;
				if(l[a].b==0.000) continue;
				if(between(p[a],tp)==true)
				{
					//printf("in\n");
					if( tp.y - (-l[a].a*tp.x -l[a].c) < -EPS) continue;
					//printf("%d %d %d %d %d\n",a,p[a].x1,p[a].y1,p[a].x2,p[a].y2);
					//printf("%lf %lf %lf\n",l[a].a,l[a].b,l[a].c);
					tp.x = p[a].x2;
					tp.y = max(0,p[a].y2);
				}
			}
			printf("%d\n",tp.x);
		}
	}
}
