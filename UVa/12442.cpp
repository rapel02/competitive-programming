#include<bits/stdc++.h>
using namespace std;

bool vis[50005];
int tot[50005];

vector<int> vec[50005];

void check(int pos)
{
	vis[pos] = true;
	tot[pos] = 1;
	int sz = vec[pos].size();
	for(int a=0;a<sz;a++)
	{
		int nx = vec[pos][a];
		if(vis[nx] == false) check(nx);
		tot[pos] += tot[nx];
	}
}

int main()
{
	int ntc;
	cin>>ntc;
	for(int tc=1;tc<=ntc;tc++)
	{
		int n;
		cin>>n;
		for(int a=0;a<n;a++)
		{
			int t,f;
			cin>>t>>f;
			vec[t].push_back(f);
		}
		int maxi = 0;
		int rem = 0;
		for(int a=1;a<=n;a++)
		{
			if(vis[a] == false)
			{
				check(a);
				if(tot[a] > maxi)
				{
					maxi = tot[a];
					rem = a;
				}
			}
		}
		printf("Case %d: %d\n",tc,rem);
		for(int a=1;a<=n;a++) vis[a] = false,vec[a].clear(),tot[a] = 0;
	}
}
