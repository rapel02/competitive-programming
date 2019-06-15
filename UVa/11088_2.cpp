#include<bits/stdc++.h>
using namespace std;

int dp[1<<16];
int n;
int arr[16];
int compute(int pos,int k,int val)
{
	//printf("%d %d %d\n",pos,k,val);
	int t = 0;
	if(dp[pos]!=-1) return dp[pos];
	if((1<<n)-1 == pos)
	{
		if(k==3 && val>=20) return 1;
		return 0;
	}
	if(k==3 && val>=20) t = 1, val = 0, k = 0;
	dp[pos] = 0;
	for(int a=0;a<n;a++)
	{
		if((pos & (1<<n)) == 0)
		{
			dp[pos] = max(dp[pos], t + compute(pos + (1<<a),k+1,val + arr[a]));
		}
	}
	printf("%d %d %d %d\n",pos,k,val,dp[pos]);
	return dp[pos];
}

int main()
{
	int tc =0 ;
	while(scanf("%d",&n),n)
	{
		tc++;
		for(int a=0;a<n;a++) scanf("%d",&arr[a]);
		memset(dp,-1,sizeof(dp));
		printf("Case %d: %d\n",tc,compute(0,0,0));
	}
}
