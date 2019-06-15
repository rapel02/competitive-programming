#include<bits/stdc++.h>
using namespace std;

int t[4][15];
int dp[3][15][400];
int n;
int compute(int person,int prob,int time)
{
	if(dp[person][prob][time]!=-1) return dp[person][prob][time];
	if(prob==n) return 0;
	dp[person][prob][time] = compute(person,prob+1,time);
	for(int a=1;a<=2;a++)
		dp[person][prob][time] = max(dp[person][prob][time],compute((person+a)%3,prob+1,time+t[person][prob+1])+1);
	return dp[person][prob][time];
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
			compute(a,0,0);
		int ans = 0;
		for(int a=0;a<3;a++)
			for(int b=0;b<=300;b++)
				ans = max(ans,dp[a][0][b]);
		printf("%d\n",ans);
	}
}
