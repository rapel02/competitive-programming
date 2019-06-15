#include<bits/stdc++.h>
using namespace std;

int dp[1500][1500];
int len1,len2;
char in1[1500],in2[1500];

int compute(int i,int j)
{
	if(i==len1) return len2 - j;
	if(j==len2) return len1 - i;
	if(dp[i][j]!=-1) return dp[i][j];
	if(in1[i]==in2[j]) return dp[i][j] = compute(i+1,j+1);
	else
	{
		return dp[i][j] = min(compute(i,j+1),min(compute(i+1,j),compute(i+1,j+1)))+1;
	}
}

int main()
{
	while(scanf("%d %s",&len1,in1)!=EOF)
	{
		memset(dp,-1,sizeof(dp));
		scanf("%d %s",&len2,in2);
		printf("%d\n",compute(0,0));
	}
}
