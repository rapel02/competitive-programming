#include<bits/stdc++.h>
#define pb push_back
using namespace std;

vector<int> vec[105];

int match[105];
bool vis[105];

int gcd(int a,int b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}

int aug(int pos)
{
	if(vis[pos]==true) return 0;
	vis[pos] = true;
	int sz = vec[pos].size();
	for(int a=0;a<sz;a++)
	{
		int next = vec[pos][a];
		if(match[next]==-1 ||aug(match[next])==1)
		{
			match[next] = pos;
			return 1;
		}
	}
	return 0;
}
int aa[105],bb[105];

int main()
{
	int tc;
	scanf("%d",&tc);
	for(int a=1;a<=tc;a++)
	{
		int n,m;
		scanf("%d",&n);
		for(int b=0;b<n;b++)
			scanf("%d",&aa[b]);
		scanf("%d",&m);
		for(int b=0;b<m;b++)
		{
			scanf("%d",&bb[b]);
			for(int c=0;c<n;c++)
			{
				int gc = gcd(aa[c],bb[b]);
				if(gc==aa[c])
				{
					vec[c].pb(b);
				}
			}
		}
		int mcbm = 0;
		memset(match,-1,sizeof(match));
		for(int b=0;b<n;b++)
		{
			memset(vis,false,sizeof(vis));
			mcbm += aug(b);
		}
		printf("Case %d: %d\n",a,mcbm);
		for(int b=0;b<n;b++) vec[b].clear();
	}
}
