#include<bits/stdc++.h>
using namespace std;

int n,m;

long long dp[11][1<<11];

long long compute(int pos,int bit,int tot)
{
	if(dp[pos][bit]!=-1) return dp[pos][bit];
	dp[pos][bit] = 0;
	printf("%d %d %d\n",pos,bit,tot);
	if(pos == m && tot ==n*m) return dp[pos][bit] = 1;
	if(bit==(1<<(n))-1) dp[pos][bit] = compute(pos+1,0,tot);
	for(int a=0;a<n-1;a++)
	{
		if(( bit & (1<<a) )==0 && (bit & (1<<(a+1))) ==0)
			dp[pos][bit] = compute(pos,bit + (1<<a) + (1<<(a+1)),tot+2);
	}
	if(pos!=m)
	for(int a=0;a<n;a++)
	{
		if(bit & (1<<a) ==0)
			dp[pos][bit] = compute(pos,(1<<a),tot++);
	}
	return dp[pos][bit];
}

int main()
{
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		memset(dp,-1,sizeof(dp));
		if(n>m) swap(n,m);
		printf("%lld\n",compute(1,0,0));
	}
}
