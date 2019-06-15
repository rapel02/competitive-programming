#include<bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
using namespace std;

int arr[1005][1005];
int tot[1005];
int n,m;

queue<pair<int,int > > q;
bool vis[1005];
vector<int> vec[1005];

int compute()
{
	int ans = 0;
	bool wow = false;
	for(int a=1;a<=n;a++)
	{
		if(vis[a]==true) continue;
		q.push(mp(a,1));
		int step = 0;
		bool first = true;
		while(!q.empty())
		{
			int pos = q.front().ff;
			int val = q.front().ss;
			if(pos==a&&first==false) wow=true,ans = val;
			q.pop();
			if(vis[pos]==true) continue;
			if(pos!=a) vis[pos] = true;
			int sz = vec[pos].size();
			for(int b=0;b<sz;b++)
			{
				int tar = vec[pos][b];
				//if(tar==a && val%2==1) continue;
				q.push(mp(tar,val+1));
			}
			first=false;
		}
	}
	return ans;
}

int main()
{
	while(1)
	{
		scanf("%d %d",&n,&m);
		if(n+m==0) break;
		memset(arr,0,sizeof(arr));
		memset(vis,false,sizeof(vis));
		for(int a=0;a<m;a++)
		{
			int t,f;
			scanf("%d %d",&t,&f);
			arr[t][f] = 1;
			arr[f][t] = 1;
		}
		int gan = 0;
		int enemy = 0;
		for(int a=1;a<=n;a++)
		{
			for(int b=1;b<=n;b++)
			{
				if(arr[a][b]==0&&a!=b) vec[a].pb(b);
			}
		}
		printf("%d\n",n-compute());
		for(int a=1;a<=n;a++) vec[a].clear();
	}
}
