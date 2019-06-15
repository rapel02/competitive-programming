#include<bits/stdc++.h>
using namespace std;

long long dp[6][8000];
int coin[]={50,25,10,5,1};

long long compute(long long id,long long n)
{
	if(dp[id][n]!=-1) return dp[id][n];
	if(n==0) return 1;
	if(n<0) return 0;
	if(id==5) return 0;
	dp[id][n] = 0;
	if(n-coin[id]>=0) dp[id][n] += compute(id, n-coin[id]);
	dp[id][n] += compute(id+1,n);
	return dp[id][n];
}

int main()
{
	memset(dp,-1,sizeof(dp));
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		printf("%lld\n",compute(0,n));
	}
}
