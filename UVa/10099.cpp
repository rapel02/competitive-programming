#include<bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
using namespace std;

vector<pair<int,int> > vec[150];
int n,r;
int fr,to,mn;

queue<int> q;
bool vis[150];

bool sucess(int mid)
{
	memset(vis,false,sizeof(vis));
	vis[fr] = true;
	q.push(fr);
	while(!q.empty())
	{
		int pos = q.front();
		q.pop();
		int sz = vec[pos].size();
		for(int a=0;a<sz;a++)
		{
			int nx = vec[pos][a].ff;
			int val = vec[pos][a].ss;
			if(val < mid) continue;
			if(vis[nx]==true) continue;
			vis[nx] = true;
			q.push(nx);
		}
	}
	return vis[to];
}

int main()
{
	int tc = 0;
	while(1)
	{
		tc++;
		scanf("%d %d",&n,&r);
		if(n+r==0) break;
		int lo,hi,rem;
		for(int a=0;a<r;a++)
		{
			int f,t,v;
			scanf("%d %d %d",&f,&t,&v);
			vec[f].pb(mp(t,v));
			vec[t].pb(mp(f,v));
			if(a==0) lo = v,hi = v;
			lo = min(lo,v);
			hi = max(hi,v);
		}
		scanf("%d %d %d",&fr,&to,&mn);
		while(lo<=hi)
		{
			int mid = (lo+hi)/2;
			bool res = sucess(mid);
			if(res==false) hi = mid-1;
			else lo = mid+1,rem = mid;
		}
		int ans = mn/(rem-1);
		if(mn%(rem-1)!=0) ans++;
		printf("Scenario #%d\nMinimum Number of Trips = %d\n\n",tc,ans);
		for(int a=1;a<=n;a++) vec[a].clear();
	}
}
