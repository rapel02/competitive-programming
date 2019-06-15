#include<bits/stdc++.h>
using namespace std;

int m[155][155];
int node[155];

int inset[155];
int d[155];

int reduce(int n)
{
	memset(inset,0,sizeof(inset));
	memset(d,0,sizeof(d));
	inset[node[0]] = 1;
	for(int i=1;i<n;i++) d[node[i]] = m[node[0]][node[i]];
	int ltnode = 0;
	for(int id = 1;id < n ;id++)
	{
		int nd = -1;
		for(int i = 1;i<n;i++)
		{
			if(inset[node[i]]) continue;
			if(nd == -1) nd = i;
			if(d[node[i]] > d[node[nd]]) nd = i;
		}
		inset[ node[nd] ] = 1;
		if(id == n-1)
		{
			for(int i=0;i<n;i++)
			{
				m[node[ltnode]][node[i]] += m[node[nd]][node[i]];
				m[node[i]][node[ltnode]]  = m[node[ltnode]][node[i]];
			}
			int ret = d[node[nd]];
			node[nd] = node[n-1];
			return ret;
		}
		ltnode = nd;
		for(int i=0;i<n;i++)
		{
			if(inset[node[i]]) continue;
			d[node[i]] += m[node[nd]][node[i]];
		}
	}
}

int mincut(int n)
{
	for(int i=0;i<n;i++) node[i] = i;
	int ans = 1<<30;
	while(n > 1)
	{
		ans = min(reduce(n),ans);
		n--;
	}
	return ans;
}

int main()
{
	int ntc;
	cin>>ntc;
	for(int tc=1;tc<=ntc;tc++)
	{
		int N,M;
		cin>>N>>M;
		memset(m,0,sizeof(m));
		for(int a=0;a<M;a++)
		{
			int f,t,c;
			cin>>f>>t>>c;
			f--,t--;
			m[f][t]+=c;
			m[t][f]+=c;
		}
		printf("Case #%d: %d\n",tc,mincut(N));
	}
}
