#include<bits/stdc++.h>
#define ff first
#define mp make_pair
#define ss second
#define pb push_back
using namespace std;

vector<pair<int,int> > vec[2500];

int dist[1500];

int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		int n,m;
		scanf("%d %d",&n,&m);
		for(int a=0;a<n;a++) dist[a] = 1000000000;
		for(int a=0;a<m;a++)
		{
			int f,t,v;
			scanf("%d %d %d",&f,&t,&v);
			vec[f].pb(mp(t,v));
		}
		dist[0] = 0;
		for(int a=0;a<n-1;a++)
		{
			for(int b=0;b<n;b++)
			{
				int sz = vec[b].size();
				for(int c=0;c<sz;c++)
				{
					int nx = vec[b][c].ff;
					int val = vec[b][c].ss;
					dist[nx] = min(dist[nx],dist[b] + val);
				}
			}
		}
		bool isneg = false;
		for(int b=0;b<n;b++)
		{
			int sz = vec[b].size();
			for(int c=0;c<sz;c++)
			{
				int nx = vec[b][c].ff;
				int val = vec[b][c].ss;
				if(dist[nx] > dist[b] + val) isneg = true;
			}
		}
		if(isneg) printf("possible\n");
		else printf("not possible\n");
		for(int a=0;a<n;a++) vec[a].clear();
	}
}
