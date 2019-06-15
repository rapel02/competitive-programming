#include<bits/stdc++.h>
using namespace std;

int arr[105];
int dp[50005];

int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		int n;
		scanf("%d",&n);
		int tot = 0;
		for(int a=0;a<n;a++) 
		{
			scanf("%d",&arr[a]);
			tot+=arr[a];
		}
		memset(dp,0,sizeof(dp));
		dp[0] = 1;
		for(int a=0;a<n;a++)
		{
			for(int c = tot;c>=arr[a];c--)
			{
				if(dp[c-arr[a]]!=0)
				{
					dp[c] = 1;
				}
			}
		}
		int ans = 0;
		for(int c=tot/2;c>=0;c--)
		{
			if(dp[c]!=0)
			{
				ans = c;
				break;
			}
		}
		printf("%d\n",tot - ans - ans);
	}
}
