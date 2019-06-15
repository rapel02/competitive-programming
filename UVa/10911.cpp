#include<bits/stdc++.h>
#define INF  1e+9
using namespace std;

typedef struct{
	double x,y;
}Mhs;

Mhs arr[20];
char temp[250];
double dp[(1<<16)];

typedef struct{
	double dist;
	int val;
}Val;

Val wow[250];

double sqr(double a)
{
	return a*a;
}

double distt(int a,int b)
{
	return sqrt(sqr(arr[a].x - arr[b].x) + sqr(arr[a].y - arr[b].y));
}

double fmin(double a,double b)
{
	if(a-b >= 0.0000000001) return b;
	return a;
}

int main()
{
	int k = 0;
	int n;
	while(scanf("%d",&n),n)
	{
		k++;
		for(int a=0;a<(1<<16);a++) dp[a] = INF;
		for(int a=0;a<2*n;a++)
		{
			scanf("%s %lf %lf",temp,&arr[a].x,&arr[a].y);
		}
		int w = 0;
		for(int a=0;a<2*n;a++)
			for(int b=a+1;b<2*n;b++)
			{
				wow[w].dist = distt(a,b);
				wow[w].val = ((1<<a) + (1<<b));
				w++;
			}
		dp[0] = 0.0000;
		for(int a=0;a<w;a++)
		{
			for(int b=0;b<(1<<(2*n) );b++)
			{
				if( (b & wow[a].val ) ==0)
					dp[b + wow[a].val] = fmin(dp[b + wow[a].val], dp[b] + wow[a].dist );
			}
		}
		printf("Case %d: %.2lf\n",k,dp[ (1<<(2*n) )- 1]);
	}
}
