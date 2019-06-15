#include<bits/stdc++.h>
using namespace std;

int dp[150][150];

int in1[150],in2[150];

int compute(int i,int j)
{
	if(i==-1 || j==-1) return 0;
	if(dp[i][j]!=-1) return dp[i][j];
	if(in1[i]==in2[j]) return dp[i][j] = compute(i-1,j-1) + 1;
	else return dp[i][j] = max(compute(i-1,j), compute(i,j-1));
}

int main()
{
	int n,m;
	int k = 0;
	while(1)
	{
		k++;
		scanf("%d %d",&n,&m);
		if(n+m==0) break;
		memset(dp,-1,sizeof(dp));
		for(int a=0;a<n;a++) scanf("%d",&in1[a]);
		for(int a=0;a<m;a++) scanf("%d",&in2[a]);
		printf("Twin Towers #%d\n",k);
		printf("Number of Tiles : %d\n\n",compute(n-1,m-1));
	}
}
