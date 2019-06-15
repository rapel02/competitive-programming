#include<bits/stdc++.h>
using namespace std;

long long dp[2][55];

void pre()
{
	dp[0][1] = 1;
	dp[1][1] = 1;
	for(int a=2;a<=52;a++)
	{
		dp[0][a] = dp[0][a-1] + dp[1][a-1];
		dp[1][a] = dp[0][a-1];
	}
}

int main()
{
	pre();
	int ntc;
	scanf("%d",&ntc);
	for(int tc=1;tc<=ntc;tc++)
	{
		int n;
		scanf("%d",&n);
		printf("Scenario #%d:\n%lld\n\n",tc,dp[0][n] + dp[1][n]);
	}
}
