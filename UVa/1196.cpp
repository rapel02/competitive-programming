#include<bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

pair<int,int> p[10005];
int dp[10005];

int main()
{
	int n;
	while(scanf("%d",&n),n)
	{
		for(int a=0;a<n;a++) scanf("%d %d",&p[a].ff,&p[a].ss);
		sort(p,p+n);
		memset(dp,0,sizeof(dp));
		int ans = 0;
		dp[0] = 1;
		for(int a=1;a<n;a++)
		{
			dp[a] = 1;
			for(int b=a-1;b>=0;b--)
			{
				if(p[a].ff >= p[b].ff && p[a].ss >= p[b].ss)
				{
					dp[a] = max(dp[a],dp[b] + 1);
				}
			}
			ans = max(ans,dp[a]);
		}
		printf("%d\n",ans);
	}
	printf("*\n");
}
