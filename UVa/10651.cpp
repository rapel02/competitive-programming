#include<bits/stdc++.h>
using namespace std;

int dp[1<<13];
int k = 0;

bool isValid(int *val)
{
	k = 0;
	for(int a=0;a<=9;a++)
	{
		if(val[a]==0 && val[a+1]==1 && val[a+2]==1) return true;
		if(val[a]==1 && val[a+1]==1 && val[a+2]==0) return true;
	}
	for(int a=0;a<12;a++) if(val[a]==1) k++;
	return false;
}

int compute(int val[])
{
	int s = 0;
	for(int a=0;a<12;a++)
	{
		s = s*2 + val[a];
	}
	if(dp[s]!=-1) return dp[s];
	if(isValid(val))
	{
		dp[s] = 100;
		for(int a=0;a<=9;a++)
		{
			if(val[a]==0 && val[a+1]==1 && val[a+2]==1)
			{
				int waw[15];
				for(int b=0;b<12;b++) waw[b] = val[b];
				waw[a] = 1,waw[a+1] = 0,waw[a+2] = 0;
				dp[s] = min(dp[s],compute(waw));
			}
			if(val[a]==1 && val[a+1]==1 && val[a+2]==0)
			{
				int waw[15];
				for(int b=0;b<12;b++) waw[b] = val[b];
				waw[a] = 0,waw[a+1] = 0,waw[a+2] = 1;
				dp[s] = min(dp[s],compute(waw));
			}
		}
		return dp[s];
	}
	else return dp[s] = k;
}

char in[15];

int main()
{
	int n;
	scanf("%d",&n);
	int val[15];
	memset(dp,-1,sizeof(dp));
	while(n--)
	{
		scanf("%s",in);
		memset(val,0,sizeof(val));
		for(int a=0;a<12;a++) if(in[a]=='o') val[a] = 1;
		printf("%d\n",compute(val));
	}
}
