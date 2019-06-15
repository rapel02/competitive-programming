#include<bits/stdc++.h>
using namespace std;

long long dp[35];

void pre()
{
	dp[1] = 1;
	dp[2] = 3;
	for(int a=3;a<=30;a++) dp[a] = dp[a-1] + 2 * dp[a-2];
}

int main()
{
	pre();
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		int n;
		scanf("%d",&n);
		printf("%lld\n",dp[n]);
	}
}
