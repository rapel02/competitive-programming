#include<bits/stdc++.h>
#define INF 1e+9
using namespace std;

int arr[55];

int dp[55][55];
int tot,n;

int compute(int l,int r)
{
	if(l+1==r) return 0;
	if(dp[l][r]!=-1) return dp[l][r];
	int ans = INF;
	for(int i=l+1;i<r;i++)
	{
		ans = min(ans,arr[r]-arr[l] + compute(l,i) + compute(i,r));
	}
	dp[l][r] = ans;
	return ans;
}

int main()
{
	while(scanf("%d",&tot),tot)
	{
		memset(dp,-1,sizeof(dp));
		scanf("%d",&n);
		arr[0] = 0;
		for(int a=1;a<=n;a++)
		{
			scanf("%d",&arr[a]);
		}
		arr[n+1] = tot;
		printf("The minimum cutting is %d.\n",compute(0,n+1));
	}
}
