#include<bits/stdc++.h>
using namespace std;

long long dp[55];

void compute()
{
	dp[0] = 1;
	dp[1] = 1;
	for(int a=2;a<=50;a++)
		dp[a] = dp[a-1] + dp[a-2];
}

int main()
{
	compute();
	while(1)
	{
		int n;
		scanf("%d",&n);
		if(n==0) break;
		printf("%lld\n",dp[n]);
	}
}
