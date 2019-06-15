#include<bits/stdc++.h>
using namespace std;

int t[3][13];
int dp[3][290][(1<<12)];
int n;
int compute(int person,int time,int solve)
{
	if(dp[person][time][solve]!=-1) return dp[person][time][solve];
	dp[person][time][solve] = 0;
	for(int a=1;a<=n;a++)
	{
		if(time + t[person][a]<=280 && ((1<<(a-1))&solve)==0)
		{
			for(int b=1;b<=2;b++)
				dp[person][time][solve] = max(dp[person][time][solve],compute((person+b)%3,time+t[person][a],solve+(1<<(a-1)))+1);
		}
	}
	return dp[person][time][solve];
}


int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		memset(dp,-1,sizeof(dp));
		scanf("%d",&n);
		for(int a=0;a<3;a++)
			for(int b=1;b<=n;b++)
				scanf("%d",&t[a][b]);
		for(int a=0;a<3;a++)
			dp[a][0][0] = compute(a,0,0);
		int ans = 0;
		for(int a=0;a<3;a++)
				ans = max(ans,dp[a][0][0]);
		printf("%d\n",ans);
	}
}
