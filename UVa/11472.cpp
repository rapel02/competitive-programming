#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;

long long dp[1500][10][150];
int n,m;

long long compute(long long bit,long long num,long long pos)
{
	if(dp[bit][num][pos]!=-1) return dp[bit][num][pos];
	if(bit== ((1<<n) - 1) ) dp[bit][num][pos] = 1;
	else dp[bit][num][pos] = 0;
	if(pos==m) return dp[bit][num][pos];
	if(pos==0)
		for(int a=1;a<n;a++)
			dp[bit][num][pos] = (dp[bit][num][pos] + compute(bit | (1<<a), a,pos+1) ) %mod;
	else
	{
	//	printf("%d %d %d %lld\n",bit,num,pos,dp[bit][num][pos]);
		if(num!=0) dp[bit][num][pos] = (dp[bit][num][pos] + compute(bit | (1<<(num-1)), num-1,pos+1) )%mod;
		if(num!=(n-1)) dp[bit][num][pos] = (dp[bit][num][pos] + compute(bit | (1<<(num+1)), num+1,pos+1) ) %mod;
	}
	//printf("res: %d %d %d %lld\n",bit,num,pos,dp[bit][num][pos]);
	return dp[bit][num][pos];
}

int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		memset(dp,-1,sizeof(dp));
		scanf("%d %d",&n,&m);
		if(m<2) printf("0\n");
		else printf("%lld\n",compute(0,0,0));
	}
}
