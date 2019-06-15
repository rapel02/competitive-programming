#include<bits/stdc++.h>
using namespace std;

int stt[50005],par[50005];

int find(int a)
{
	if(a == par[a]) return a;
	return par[a] = find(par[a]);
}

int main()
{
	int n,m;
	int tc = 0;
	while(cin>>n>>m && (n+m)!=0)
	{
		for(int a=1;a<=n;a++) stt[a] = 0,par[a] = a;
		int ans = 0;
		for(int a=0;a<m;a++)
		{
			int t,f;
			cin>>t>>f;
			if(find(t) != find(f)) par[find(t)] = find(f);
		}
		for(int a=1;a<=n;a++)
		{
			if(stt[find(a)] == 1) continue;
			stt[find(a)] = 1;
			ans++;
		}
		printf("Case %d: %d\n",++tc,ans);
	}
}
