#include<bits/stdc++.h>
using namespace std;

int t[150];
double precom[150][150];
double dp[150][150];
double b,r,v,e,f;

double compute(int ll,int rr)
{
	if(ll>rr) return 0;
	if(dp[ll][rr]!=1e+9) return dp[ll][rr];
	double dt = 0;
	for(int a=0;a< t[rr]-t[ll];a++)
	{
		if(a>=r ) dt+=1.0/(v - e*(a-r));
		else dt+=1.0/(v - f*(r-a));
	}
	dp[ll][rr] = dt;
	if(ll==rr) return 0;
	for(int a=ll;a<rr;a++)
	{
		dp[ll][rr] = min(dp[ll][rr],compute(ll,a) +b + compute(a,rr));
	}
	return dp[ll][rr];
}

int main()
{
	int n;
	while(scanf("%d",&n),n)
	{
		for(int a=1;a<=n;a++) scanf("%d",&t[a]);
		scanf("%lf %lf %lf %lf %lf",&b,&r,&v,&e,&f);
		for(int a=0;a<150;a++) for(int b=0;b<150;b++) dp[a][b] = 1e+9;
		printf("%.4lf\n",compute(0,n));
	}
}
