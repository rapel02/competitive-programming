#include<bits/stdc++.h>
using namespace std;

int dp[105][105];
int len1,len2;
char in1[105],in2[105];
int edit_distance(int i,int j)
{
	if(dp[i][j]!=-1) return dp[i][j];
	if(i==len1) return dp[i][j] = len2-j;
	if(j==len2) return dp[i][j] = len1-i;
	if(in1[i]==in2[j])
	{
		dp[i][j] = edit_distance(i+1,j+1);
	}
	else
	{
		dp[i][j] = min(edit_distance(i,j+1)+1,min(edit_distance(i+1,j)+1,edit_distance(i+1,j+1)+1));
	}
	return dp[i][j];
}

int main()
{
	int tc;
	scanf("%d",&tc); getchar();
	while(tc--)
	{
		memset(dp,-1,sizeof(dp));
		gets(in1);
		gets(in2);
		len1 = strlen(in1);
		len2 = strlen(in2);
		printf("%lld\n",edit_distance(0,0));
	}
}
