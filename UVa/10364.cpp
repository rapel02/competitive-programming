#include<bits/stdc++.h>
using namespace std;

int arr[40];
int m;
int dp[1<<21];
int tot = 0;
int compute(int bit,int val)
{
	if(dp[bit]!=-1) return dp[bit];
	dp[bit] = 0;
	if(bit==(1<<m)-1) return dp[bit] =0;
	for(int a=1;a<=m;a++)
	{
		if( ((bit & (1<<(a-1)) )== 0) && val + arr[a] <=tot)
		{
			if(val+arr[a] == tot) dp[bit] = max(dp[bit],compute(bit + (1<<(a-1)),0) + 1);
			else dp[bit] = max(dp[bit],compute(bit + (1<<(a-1)),val+arr[a]));
		}
	}
	//printf("%d %d %d %d\n",pos,bit,val,dp[pos][bit]);
	return dp[bit];
}

int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		memset(dp,-1,sizeof(dp));
		scanf("%d",&m);
		tot = 0;
		for(int a=1;a<=m;a++)
		{
			scanf("%d",&arr[a]);
			tot+=arr[a];
		}
		if(tot%4!=0) printf("no\n");
		else
		{
			tot/=4;
			if(compute(0,0)!=4) printf("no\n");
			else printf("yes\n");
		}
	}
}
