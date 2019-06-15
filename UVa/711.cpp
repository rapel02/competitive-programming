#include<bits/stdc++.h>
using namespace std;

int arr[15];
int dp[120005];

int main()
{
	int tc = 0;
	while(1)
	{
		tc++;
		memset(dp,0,sizeof(dp));
		int tot = 0;
		for(int a=1;a<=6;a++)
		{
			scanf("%d",&arr[a]);
			tot = tot + arr[a] * a;
		}
		if(tot==0) break;
		if(tot%2==0)
		{
			dp[0] = 1;
			bool fn = false;
			for(int a = tot/2;a>=0;a--)
			{
				for(int b=6;b>=1;b--)
				{
					for(int c = 0;c<arr[b];c++)
					{
						if(a-b<0) break;
						if(dp[a-b]==1) dp[a] = 1;
						if(dp[tot/2] == 1) fn = true;
						if(fn) break;
					}
					if(fn) break;
				}
				if(fn) break;
			}
		}
		printf("Collection #%d:\n",tc);
		if(tot%2==1 || dp[tot/2]!=1) printf("Can't be divided.\n");
		else printf("Can be divided.\n");
		printf("\n");
	}
}
