#include<bits/stdc++.h>
using namespace std;

long long dp[15][15];

void pre()
{
	dp[0][0] = 1;
	for(int a=1;a<=13;a++)
	{
		for(int b=0;b<=a;b++)
		{
			if(b==a || b==0) dp[a][b] = 1;
			else dp[a][b] = dp[a-1][b] + dp[a-1][b-1];
		}
	}
}

int main()
{
	pre();
	long long n,k;
	while(cin>>n>>k)
	{
		long long ans = 1;
		for(int a=1;a<=k;a++)
		{
			long long p;
			cin>>p;
			ans *= dp[n][p];
			n-=p;
		}
		printf("%lld\n",ans);
	}
}
