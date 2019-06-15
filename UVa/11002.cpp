#include<bits/stdc++.h>
using namespace std;

int num[80][80];

int dp[80][80][8000];
int pos;
int n;

void compute(int pos,int col,int val)
{
	if(dp[pos][col][4000+val] == 1) return ;
	dp[pos][col][4000+val] = 1;
	if(pos==1) return ;
//	printf("%d %d %d\n",pos,col,val);
	compute(pos-1,col,val+num[pos-1][col]);
	compute(pos-1,col,val-num[pos-1][col]);
	if(pos>n)
	{
		compute(pos-1,col+1,val+num[pos-1][col+1]);
		compute(pos-1,col+1,val-num[pos-1][col+1]);
	}
	if(col>1)
	{
		compute(pos-1,col-1,val+num[pos-1][col-1]);
		compute(pos-1,col-1,val-num[pos-1][col-1]);
	}
}

int main()
{
	while(1)
	{
		scanf("%d",&n);
		if(n==0) break;
		memset(dp,0,sizeof(dp));
		for(int a=1;a<=2*n - 1;a++)
			for(int b=1;b<=min(a,2*n - a);b++)
				scanf("%d",&num[a][b]);
		compute(2*n-1,1,num[2*n-1][1]);
		int ans = 1000000000;
		for(int a=0;a<8000;a++)
		{
			if(dp[1][1][a]==1)
			{
				ans = min(ans,abs(a-4000));
			}
		}
		printf("%d\n",ans);
	}
}
