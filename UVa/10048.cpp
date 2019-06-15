#include<bits/stdc++.h>
#define ff first
#define mp make_pair
#define ss second
#define pb push_back
using namespace std;

const int INF = 1000000000;

int di[150];
bool vis[150];
queue<int> q;

vector<pair<int,int> > vec[150];


bool success(int l,int r,int mid)
{
	while(!q.empty()) q.pop();
	memset(vis,false,sizeof(vis));
	vis[l] = true;
	q.push(l);
	while(!q.empty())
	{
		int pos = q.front();
		q.pop();
		if(pos==r) return true;
		int sz = vec[pos].size();
		for(int a=0;a<sz;a++)
		{
			int nx = vec[pos][a].ff;
			int val = vec[pos][a].ss;
			if(vis[nx]==true) continue;
			if(mid < val) continue;
			vis[nx] = true;
			q.push(nx);
		}
	}
	return false;
}

int main()
{
	int c,s,q;
	int tc = 0;
	while(1)
	{
		scanf("%d %d %d",&c,&s,&q);
		if(c==0 && s==0 && q==0) break;
		if(tc!=0) printf("\n");
		tc++;
		printf("Case #%d\n",tc);
		for(int a=0;a<s;a++)
		{
			int c1,c2,d;
			scanf("%d %d %d",&c1,&c2,&d);
			vec[c1].pb(mp(c2,d));
			vec[c2].pb(mp(c1,d));
		}
		for(int a=0;a<q;a++)
		{
			int l,r;
			scanf("%d %d",&l,&r);
			int lo = 0;
			int hi = 1000000;
			int rem = -1;
			while(lo<=hi)
			{
				int mid = (lo+hi)/2;
				if(success(l,r,mid)==true) hi = mid-1, rem = mid;
				else lo = mid+1;
			}
			if(rem==-1) printf("no path\n");
			else printf("%d\n",rem);
		}
		for(int a=0;a<=c;a++) vec[a].clear();
	}
}
