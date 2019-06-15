#include<bits/stdc++.h>
#define eps 1e-9
#define ff first
#define ss second
using namespace std;

struct Point{
	double x;
	double y;
	Point(){
		
	}
}pos[100005],ch[100006];

double change(double a)
{
//	int b = 100*a;
//	if(b%10>=5)
//	{
//		b/=10;
//		b++;
//	}
//	else
//	{
//		b/=10;
//	}
//	double c = b;
//	return c/10;
	return a;
}

int n,sz;

bool cmp(Point a,Point b)
{
	if(a.x<b.x) return true;
	if(a.x == b.x) return a.y<b.y;
	return false;
}

double cross(Point a,Point b,Point c)
{
	return (b.x - a.x)*(c.y - a.y) - (b.y - a.y) *(c.x - a.x);
}

double sqr(double x)
{
	return x*x;
}

double dist(Point a,Point b)
{
	return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
}

void CHULL()
{
	sort(pos,pos+n,cmp);
	sz = 0;
	for(int a=0;a<n;a++)
	{
		while(sz>=2 && cross(ch[sz-2],ch[sz-1],pos[a])>0) sz--;
		ch[sz++] = pos[a];
	}
	for(int a = n-2, t = sz+1;a>=0;a--)
	{
		while(sz>=t && cross(ch[sz-2],ch[sz-1],pos[a])>0) sz--;
		ch[sz++] = pos[a];
	}
//	printf("%d\n",sz);
}

int main()
{
	int k = 0;
	bool first = true;
	while(1)
	{
		double tot = 0;
		k++;
		scanf("%d",&n);
		if(n==0) break;
		first = false;
		for(int a=0;a<n;a++)
		{
			scanf("%lf %lf",&pos[a].x,&pos[a].y);
		}
		printf("Region #%d:\n",k);
		if(n!=1)
		{
			CHULL();
			for(int a=0;a<sz-1;a++)
			{
				printf("(%.1lf,%.1lf)-",change(ch[a].x),change(ch[a].y));
				if(a!=(sz-1))tot = tot + dist(ch[a],ch[(a+1)%n]);
			}
			printf("(%.1lf,%.1lf)",change(ch[0].x),change(ch[0].y));
			printf("\nPerimeter length = %.2lf\n",tot);
		}
		else
		{
			int a = 0;
			ch[a] = pos[a];
			printf("(%.1lf,%.1lf)-",change(ch[a].x),change(ch[a].y));
			printf("(%.1lf,%.1lf)",change(ch[a].x),change(ch[a].y));
			printf("\nPerimeter length = %.2lf\n",tot);
		}
		printf("\n");
	}
}
