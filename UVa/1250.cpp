#include<bits/stdc++.h>
using namespace std;

struct Point{
	double x,y,p;
}p[1500];

double dp[1500];

double sqr(double x)
{
	return x*x;
}

double dist(int a,int b)
{
	return sqrt(sqr(p[a].x - p[b].x) + sqr(p[a].y - p[b].y));
}

int main()
{
	int n;
	while(scanf("%d",&n),n)
	{
		p[0].x = 0,p[0].y = 0 ,p[0].p = 0;
		p[n+1].x = 100,p[n+1].y = 100,p[n+1].p = 0;
		for(int a=1;a<1500;a++) dp[a] = 1e+9;
		for(int a=1;a<=n;a++) scanf("%lf %lf %lf",&p[a].x,&p[a].y,&p[a].p);
		dp[0] = 0;
		for(int a=1;a<=n+1;a++)
		{
			double perr = 0;
			for(int b=a-1;b>=0;b--)
			{
				dp[a] = min(dp[a],dp[b] + dist(a,b) + 1 + perr);
				perr += p[b].p;
			}
			//printf("%.3lf\n",dp[a]);
		}
		//cout<<dp[n+1]<<endl;
		dp[n+1] +=0.0005;
		dp[n+1] *=1000;
		printf("%d.%03d\n",(int)dp[n+1]/1000,((int)dp[n+1])%1000);
	}
}
