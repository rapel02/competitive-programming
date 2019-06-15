#include<bits/stdc++.h>
using namespace std;

struct Build{
	int x,y,t;
}temp,p[600];

bool cmp(Build a,Build b)
{
	if(a.x < b.x) return true;
	if(a.x==b.x) return a.y < b.y;
	return false;
}

int dp[1500];

int main()
{
	int n;
	int tc = 0;
	while(scanf("%d",&n),n)
	{
		tc++;
		int k = 0;
		memset(dp,0,sizeof(dp));
		for(int a=0;a<n;a++)
		{
			int x,y,z;
			scanf("%d %d %d",&x,&y,&z);
			p[k++]={x,y,z};
			p[k++]={x,z,y};
			p[k++]={y,x,z};
			p[k++]={y,z,x};
			p[k++]={z,x,y};
			p[k++]={z,y,x};
		}
		sort(p,p+k,cmp);
		int ans = 0;
		for(int a=0;a<k;a++)
		{
			dp[a] = p[a].t;
			for(int b=a-1;b>=0;b--)
			{
				if(p[a].x > p[b].x && p[a].y > p[b].y) dp[a] = max(dp[a],dp[b] + p[a].t);
			}
			ans = max(ans,dp[a]);
		}
		printf("Case %d: maximum height = %d\n",tc,ans);
	}
}
