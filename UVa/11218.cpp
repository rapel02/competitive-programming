#include<bits/stdc++.h>
using namespace std;

int dp[1<<9];
bool vis[1<<9];

int main()
{
	int n;
	int k =0;
	while(scanf("%d",&n),n)
	{
		k++;
		int a,b,c,v;
		memset(dp,0,sizeof(dp));
		memset(vis,0,sizeof(vis));
		for(int w=0;w<n;w++)
		{
			scanf("%d %d %d %d",&a,&b,&c,&v);
			a--,b--,c--;
			int val = (1<<a) + (1<<b) + (1<<c);
			vis[0] = true;
			for(int a=0;a<(1<<9);a++)
			{
				if((a&val)==0 && vis[a] ==true) 
				{
					vis[a+ val] = true;
					dp[a + val] = max(dp[a + val],dp[a] + v);
				}
			}
		}
		if(vis[(1<<9)-1]==false) printf("Case %d: -1\n",k);
		else printf("Case %d: %d\n",k,dp[(1<<9)-1]);
	}
}
