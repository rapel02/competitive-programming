#include<bits/stdc++.h>
using namespace std;

long long dp[150][1<<12];

int main()
{
	int n,m;
	while(scanf("%d %d",&m,&n)!=EOF)
	{
		memset(dp,0,sizeof(dp));
		if(m > n) swap(m,n);
		int bit = 1<<m;
		dp[0][bit-1] = 1;
		for(int a=0;a<n;a++)
		{
			for(int b=0;b<m;b++)
			{
				for(int c=0;c<bit;c++)
				{
					if(b!=0 && (c & (1<<(b-1)))==0 && ((c & (1<<b)) != 0)) dp[a*m + b + 1][c | (1<<(b-1))]+= dp[a*m + b][c];
					dp[a*m + b + 1][c ^ (1<<(b))] += dp[a*m + b][c];
				}
			}
		}
		printf("%lld\n",dp[n*m][bit-1]);
	}
}
