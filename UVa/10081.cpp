#include<bits/stdc++.h>
using namespace std;

double dp[10][150];
int k,n;

void compute()
{
	for(int a=0;a<=k;a++) dp[a][1] = 1.0/(k+1);
	for(int b=2;b<=n;b++)
		for(int a=0;a<=k;a++)
		{
			for(int c=max(0,a-1);c<=min(k,a+1);c++) dp[a][b]+=dp[c][b-1];
			dp[a][b] = dp[a][b] / (k+1);
		}
}

int main()
{
	while(scanf("%d %d",&k,&n)!=EOF)
	{
		memset(dp,0,sizeof(dp));
		compute();
		double ans = 0;
		for(int a=0;a<=k;a++) ans += dp[a][n];
		printf("%.5lf\n",ans*100);
	}
}
