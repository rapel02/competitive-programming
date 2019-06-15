#include<bits/stdc++.h>
using namespace std;

int k,d;
char in[1500][1500];

int top[1500];
int bot[1500];
int diff[1500];

int dp[1500][1500];

int px[]={1,-1,0,0};
int py[]={0,0,1,-1};

bool vis[1500][1500];

int r,c;

void flood_fill(int n,int y,int x)
{
	if(n==1) top[x] = max(top[x],y);
	else if(n==0) bot[x] = min(bot[x],y);
	for(int a=0;a<4;a++)
	{
		int yy = y + py[a];
		int xx = x + px[a];
		if(yy<0 || xx<0 || yy>=r || xx>=c) continue;
		if(in[yy][xx]=='.') continue;
		if(vis[yy][xx]==true) continue;
		vis[yy][xx] = true;
		flood_fill(n,yy,xx);
	}
}

int main()
{
	while(scanf("%d %d",&r,&c)!=EOF)
	{
		scanf("%d %d",&k,&d);
		for(int a=0;a<=1000;a++)
			for(int b=0;b<=1000;b++) dp[a][b] = 1e+9;
		for(int a=0;a<r;a++) scanf("%s",in[a]);
		memset(top,0,sizeof(top));
		for(int a=0;a<c;a++) bot[a] = r;
		memset(vis,false,sizeof(vis));
		flood_fill(1,0,0);
		flood_fill(0,r-1,0);
		for(int a=0;a<c;a++) diff[a] = bot[a] - top[a] - 1;
		for(int a=c-1;a>=0;a--) dp[1][a] = min(dp[1][a+1],diff[a]);
		int ans = 1e+9;
		if(k==1) ans = dp[1][0];
		for(int a=2;a<=k;a++)
		{
			for(int b=c-1;b>=0;b--)
			{
				if(b+d+1>=c) continue;
				else dp[a][b] = min(dp[a][b],min(dp[a][b+1],dp[a-1][b+d+1] + diff[b]));
				if(a==k) ans = min(ans,dp[a][b]);
			}
		}
		printf("%d\n",ans);
	}
}
