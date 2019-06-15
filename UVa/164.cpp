#include<bits/stdc++.h>
using namespace std;

int dp[150][150];
char in1[30],in2[30];
int len1,len2;
int stats[150][150];

int compute(int a,int b)
{
	if(a==len1)
	{
		for(int c=b;c<len2;c++) stats[a][c] = 1; //add
		return dp[a][b] = len2 - b;
	}
	if(b==len2) 
	{
		for(int c=a;c<len1;c++) stats[c][b] = -1; //delete
		return dp[a][b] = len1 - a;
	}
	if(dp[a][b]!=-1) return dp[a][b];
	if(in1[a]==in2[b])
	{
		stats[a][b] = 0; // ignore
		return dp[a][b] = compute(a+1,b+1);
	}
	else
	{
		dp[a][b] = compute(a+1,b) + 1; //delete
		stats[a][b] = -1; // delete
		int v1 = compute(a,b+1) + 1; //add
		if(dp[a][b] > v1)
		{
			stats[a][b] = 1; // add
			dp[a][b] = v1;
		}
		int v2 = compute(a+1,b+1) + 1; //change
		if(dp[a][b] > v2)
		{
			stats[a][b] = 2; // change
			dp[a][b] = v2;
		}
		return dp[a][b];
	}
}

int add = 0;

void backtracking(int a,int b)
{
	if(a>=len1 && b>=len2) return ;
	if(stats[a][b]==0)
	{
		backtracking(a+1,b+1);
	}
	if(stats[a][b]==2)
	{
		printf("C%c%02d",in2[b],a+ add + 1);
		backtracking(a+1,b+1);
	}
	if(stats[a][b]==1)
	{
		printf("I%c%02d",in2[b],a + add + 1);
		add++;
		backtracking(a,b+1);
	}
	if(stats[a][b]==-1)
	{
		printf("D%c%02d",in1[a],a+ add + 1);
		add--;
		backtracking(a+1,b);
	}
}

int main()
{
	while(1)
	{
		add = 0;
		scanf("%s",in1);
		if(in1[0]=='#') break;
		scanf("%s",in2);
		memset(dp,-1,sizeof(dp));
		len1 = strlen(in1);
		len2 = strlen(in2);
		compute(0,0);
		backtracking(0,0);
		printf("E\n");
		//printf("%d\n",compute(0,0));
	}
}
