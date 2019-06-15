#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

LL rem[150][150];
LL dp[150][150];
LL arr[150][150];
bool vis[150][150];
LL r,c;

void backtrack(LL row,LL col)
{
	if(col==c) return ;
	if(col!=0) printf(" ");
	printf("%lld",row+1);
	backtrack(rem[row][col],col+1);
	return ;
	
}

int main()
{
	while(scanf("%lld %lld",&r,&c)!=EOF)
	{
		memset(vis,false,sizeof(vis));
		memset(rem,0,sizeof(rem));
		memset(dp,0,sizeof(dp));
		for(int a=0;a<r;a++)
			for(int b=0;b<c;b++) scanf("%lld",&arr[a][b]);
		for(int a=0;a<r;a++) dp[a][c-1] = arr[a][c-1];
		for(int b=c-1;b>=1;b--)
		{
			for(int a=0;a<r;a++)
			{
				if(!vis[(a-1+r)%r][b-1]) 
				{
					dp[(a+r-1)%r][b-1] = dp[a][b] + arr[(a-1+r)%r][b-1];
					rem[(a-1+r)%r][b-1] = a;
				}
				else
				{
					if(dp[(a-1+r)%r][b-1] > dp[a][b] + arr[(a-1+r)%r][(b-1)])
					{
						dp[(a-1+r)%r][b-1] = dp[a][b] + arr[(a-1+r)%r][(b-1)];
						rem[(a-1+r)%r][b-1] = a;
					}
				}
				
				if(!vis[(a)%r][b-1]) 
				{
					dp[(a)%r][b-1] = dp[a][b] + arr[(a)%r][b-1];
					rem[(a)%r][b-1] = a;
				}
				else
				{
					if(dp[(a)%r][b-1] > dp[a][b] + arr[(a)%r][(b-1)])
					{
						dp[(a)%r][b-1] = dp[a][b] + arr[(a)%r][(b-1)];
						rem[(a)%r][b-1] = a;
					}
				}
				
				if(!vis[(a+1+r)%r][b-1]) 
				{
					dp[(a+r+1)%r][b-1] = dp[a][b] + arr[(a+1+r)%r][b-1];
					rem[(a+1+r)%r][b-1] = a;
				}
				else
				{
					if(dp[(a+1+r)%r][b-1] > dp[a][b] + arr[(a+1+r)%r][(b-1)])
					{
						dp[(a+1+r)%r][b-1] = dp[a][b] + arr[(a+1+r)%r][(b-1)];
						rem[(a+1+r)%r][b-1] = a;
					}
				}
				vis[(a+1+r)%r][b-1] = true;
				vis[(a-1+r)%r][b-1] = true;
				vis[(a+r)%r][b-1] = true;
			}
		}
		bool first = false;
		LL maxi = 0;
		LL ww = 0;
		for(int a=0;a<r;a++)
		{
			if(first==false) maxi = dp[a][0],ww = a;
			if(maxi>dp[a][0])
			{
				ww = a;
				maxi = dp[a][0];
			}
			first = true;
		}
		backtrack(ww,0);
		printf("\n");
		printf("%lld\n",maxi);
	}
}
