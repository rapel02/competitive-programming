#include<bits/stdc++.h>
#define INF 100000000
using namespace std;

int dp[10005][10];
int ff[10005][10];
int h;

int count()
{
	dp[0][0]=0;
	for(int a=1;a<=h;a++)
	{
		for(int b=0;b<=9;b++)
		{
			if(b!=0) dp[a][b]=min(dp[a][b],dp[a-1][b-1]+60-ff[a][b]);
			if(b!=9) dp[a][b]=min(dp[a][b],dp[a-1][b+1]+20-ff[a][b]);
			dp[a][b]=min(dp[a][b],dp[a-1][b]+30-ff[a][b]);
		}
	}
}

int main()
{
	int test;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d",&h);
		h=h/100;
		memset(dp,-1,sizeof(dp));
		for(int a=9;a>=0;a--)
			for(int b=1;b<=h;b++)
			{
				scanf("%d",&ff[b][a]);
				dp[b][a]=INF;
				dp[0][a]=INF;
			}
		count();
		for(int a=9;a>=0;a--)
		{
			for(int b=1;b<=h;b++)
				printf("%d ",dp[b][a]);
			printf("\n");
		}
		printf("%d\n",dp[h][0]);
		printf("\n");
	}
}
