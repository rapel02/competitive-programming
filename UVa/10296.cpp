#include<bits/stdc++.h>
using namespace std;

vector<int> v[20];
vector<int> odd;
long long dist[20][20];

long long dp[1<<18];
int sz[20];
int n,m;

long long compute(int size)
{
	if(dp[size]!=-1) return dp[size];
	if(size==0) return 0;
	dp[size] = 10000000;
	int sz = odd.size();
	for(int a=0;a<sz;a++)
	{
		if( (size & (1<<a) ) == 0) continue;
		for(int b=a+1;b<sz;b++)
		{
			if((size & (1<<b)) ==0) continue;
			dp[size] = min(dp[size],compute(size - (1<<b) - (1<<a)) + dist[odd[a]][odd[b]]);
		}
	}
	return dp[size];
}

int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0) break;
		scanf("%d",&m);
		long long tot = 0;
		memset(sz,0,sizeof(sz));
		for(int a=0;a<20;a++) for(int b=0;b<20;b++) dist[a][b] = 1000000000;
		memset(dp,-1,sizeof(dp));
		for(int a=0;a<m;a++)
		{
			int f,t;
			long long w;
			scanf("%d %d %lld",&f,&t,&w);
			dist[f][t] = min(dist[f][t],w);
			dist[t][f] = min(dist[t][f],w);
			v[f].push_back(t);
			v[t].push_back(w);
			tot+= w;
			sz[f]++;
			sz[t]++;
		}
		bool iseuler = true;
		for(int a=1;a<=n;a++)
			if(sz[a]%2==1) iseuler = false;
		if(iseuler) printf("%lld\n",tot);
		else
		{
			for(int k=1;k<=n;k++)
				for(int i=1;i<=n;i++)
					for(int j=1;j<=n;j++) dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
			for(int a=1;a<=n;a++)
				if(sz[a]%2==1) odd.push_back(a);
			//printf("%d\n",odd.size());
			//for(int a=0;a<odd.size();a++) printf("%d\n",odd[a]);
			printf("%lld\n",compute( (1<<(odd.size())) - 1) + tot);
		}
		odd.clear();
		for(int a=1;a<=n;a++) v[a].clear();
	}
}
