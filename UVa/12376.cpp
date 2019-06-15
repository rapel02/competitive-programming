#include<bits/stdc++.h>
#define pb push_back
using namespace std;

int tot[150];
int stp = 0;

queue<int> q;
vector<int> vec[150];

int start(int val)
{
	int point = tot[0];
	stp = 0;
	q.push(0);
	while(!q.empty())
	{
		int pos = q.front();
		stp = pos;
		q.pop();
		int sz = vec[pos].size();
		int val = 0;
		int pz = 0;
		int tar;
		for(int a=0;a<sz;a++)
		{
			tar = vec[pos][a];
			if(a==0)
			{
				val = tot[tar];
				pz = tar;
			}
			if(val<tot[tar])
			{
				val = tot[tar];
				pz = tar;
			}
		}
		if(sz!=0) q.push(pz);
		point+=val;
	}
	return point;
}

int main()
{
	int tc;
	scanf("%d",&tc);
	int k =0;
	while(tc--)
	{
		k++;
		int n,m;
		scanf("%d %d",&n,&m);
		for(int a=0;a<n;a++) scanf("%d",&tot[a]);
		for(int b=0;b<m;b++)
		{
			int t,f;
			scanf("%d %d",&t,&f);
			vec[t].pb(f);
		}
		printf("Case %d: %d ",k,start(0));
		printf("%d\n",stp);
		for(int a=0;a<n;a++) vec[a].clear();
	}
}
