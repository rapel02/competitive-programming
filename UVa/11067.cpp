#include<bits/stdc++.h>
using namespace std;

long long dp[150][150];
int r,c;
int wolf[150][150];

long long compute()
{
	for(int a=0;a<=r;a++)
	{
		for(int b=0;b<=c;b++)
		{
			if(a==0 && b==0) dp[a][b] = 1;
			if(wolf[a][b]==1)
			{
				dp[a][b] = 0;
				continue;
			}
			if(a!=0) dp[a][b] += dp[a-1][b];
			if(b!=0) dp[a][b] += dp[a][b-1];
		}
	}
	return dp[r][c];
}

int main()
{
	while(scanf("%d %d",&r,&c)!=EOF)
	{
		if(r==0 && c==0) break;
		memset(dp,0,sizeof(dp));
		memset(wolf,0,sizeof(wolf));
		int n;
		scanf("%d",&n);
		for(int a=0;a<n;a++)
		{
			int x,y;
			scanf("%d %d",&x,&y);
			wolf[x][y] = 1;
		}
		long long ans = compute();
		if(ans>1) printf("There are %lld paths from Little Red Riding Hood's house to her grandmother's house.\n",ans);
		else if(ans==1) printf("There is one path from Little Red Riding Hood's house to her grandmother's house.\n");
		else printf("There is no path.\n");
	}
}
