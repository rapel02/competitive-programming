#include<bits/stdc++.h>
using namespace std;

int dp[2500][2500];
int maxi[2500];

int tree[2500][2500];

int compute(int t,int h,int f)
{
	for(int a=0;a<=h;a++)
	{
		for(int b=0;b<t;b++)
		{
			if(a>=f) dp[b][a] = max(dp[b][a-1],maxi[a-f]) + tree[b][a];
			else dp[b][a] = dp[b][a-1] + tree[b][a];
			maxi[a] = max(maxi[a],dp[b][a]);
		}
	}
	return maxi[h];
}

int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		int t,h,f,tp;
		scanf("%d %d %d",&t,&h,&f);
		memset(tree,0,sizeof(tree));
		memset(dp,0,sizeof(dp));
		memset(maxi,0,sizeof(maxi));
		for(int a=0;a<t;a++)
		{
			scanf("%d",&tp);
			for(int b=0;b<tp;b++)
			{
				int p;
				scanf("%d",&p);
				tree[a][p]++;
			}
		}
		printf("%d\n",compute(t,h,f));
	}
	int tp;
	scanf("%d",&tp);
}
