#include<bits/stdc++.h>
#define EPS 1e-9
using namespace std;

struct Point{
	double x,y;
}star[1500];

int p[1500],h[1500];

double sqr(double x)
{
	return x*x;
}

double dist(int a,int b)
{
	return sqrt(sqr(star[a].x - star[b].x) + sqr(star[a].y - star[b].y));
}

int par(int a)
{
	if(p[a]==a) return a;
	return p[a] = par(p[a]);
}

bool issame(int a,int b)
{
	return (par(a)==par(b));
}

void joint(int a,int b)
{
	if(issame(a,b)==false)
	{
		int x = par(a);
		int y = par(b);
		if(h[x] > h[y])
		{
			p[y] = x;
		}
		else
		{
			p[x] = y;
			if(h[y]==h[x]) h[y]++;
		}
	}
}

int main()
{
	int ntc;
	int n;
	double D;
	//FILE *fp;
	//fp = fopen("11966.txt","w");
	scanf("%d",&ntc);
	for(int tc=1;tc<=ntc;tc++)
	{
		scanf("%d %lf",&n,&D);
		for(int a=0;a<n;a++) scanf("%lf %lf",&star[a].x,&star[a].y);
		for(int a=0;a<n;a++) p[a] = a,h[a] = 1;
		for(int a=0;a<n;a++)
		{
			for(int b=a+1;b<n;b++)
			{
			//	printf("%d %d %lf %lf\n",a,b,dist(a,b),D);
				if(dist(a,b)-D<EPS)
				{
					joint(a,b);
				}
			}
		}
		set<int> s;
		//for(int a=0;a<n;a++) printf("%d\n",p[a]);
		for(int a=0;a<n;a++) s.insert(par(p[a]));
		printf("Case %d: %d\n",tc,s.size());
		//fprintf(fp,"Case %d: %d\n",tc,s.size());
	}
}
