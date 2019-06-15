#include<bits/stdc++.h>
#define mp make_pair
#define ff first
#define ss second
using namespace std;

char in[25][25];

pair<int,int> p[30];

int dist[30][30];

int dp[16][1<<16];
int k;

int bitmask(int pos,int bit)
{
	if(bit==(1<<k)-1) return dist[pos][0];
	if(dp[pos][bit]!=-1) return dp[pos][bit];
	dp[pos][bit] = 1000000000;
	for(int a=0;a<k;a++)
	{
		if( (bit & (1<<a)) ==0)
		{
			dp[pos][bit] = min(dp[pos][bit], bitmask(a,bit + (1<<a)) + dist[pos][a]);
		}
	}
	return dp[pos][bit];
}

int main()
{
	int r,c;
	while(scanf("%d %d",&r,&c)!=EOF)
	{
		memset(dp,-1,sizeof(dp));
		for(int a=0;a<r;a++) scanf("%s",in[a]);
		k = 1;
		for(int a=0;a<r;a++)
		{
			for(int b=0;b<c;b++)
			{
				if(in[a][b]=='#') p[k++] = mp(a,b);
				if(in[a][b]=='L') p[0] = mp(a,b);
			}
		}
		for(int a=0;a<k;a++) for(int b=0;b<k;b++) dist[a][b] = max(abs(p[a].ff - p[b].ff),abs(p[a].ss - p[b].ss));
		printf("%d\n",bitmask(0,1));
	}
}
