#include<bits/stdc++.h>
#define INF 100000000
using namespace std;

int dp[10005][10];
int ff[10005][10];
int h;

int count(int coor,int alt)
{
	//printf("%d %d\n",coor,alt);
	if(alt<0 || alt>9) return INF;
	if(dp[coor][alt]!=-1) return dp[coor][alt];
	if(coor==h+1)
	{
		if(alt==0) return 0;
		else return INF;
	}
	return dp[coor][alt]=min(30-ff[coor][alt]+count(coor+1,alt),min(60-ff[coor][alt]+count(coor+1,alt+1),20-ff[coor][alt]+count(coor+1,alt-1)));
}

int main()
{
	int test;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d",&h);
		h=h/100;
		memset(dp,-1,sizeof(dp));
		for(int a=9;a>=0;a--)
			for(int b=1;b<=h;b++)
			{
				scanf("%d",&ff[b][a]);
			}
		count(1,0);
		for(int a=9;a>=0;a--)
		{
			for(int b=1;b<=h;b++)
				printf("%d ",dp[b][a]);
			printf("\n");
		}
		printf("%d\n",dp[1][0]);
		printf("\n");
	}
}
