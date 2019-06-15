#include<bits/stdc++.h>
using namespace std;

vector<int> vec[250];
int col[250];
int ans = 0;
bool isb;

int traverse(int pos)
{
	int c0=0,c1 = 0;
	col[pos] = 0;
	queue<int> q;
	q.push(pos);
	while(!q.empty())
	{
		int p = q.front();
		q.pop();
		int sz = vec[p].size();
		if(col[p] == 0) c0++;
		else c1++;
		for(int a=0;a<sz;a++)
		{
			int nx = vec[p][a];
			if(col[nx] == -1)
			{
				col[nx] = 1 - col[p];
				q.push(nx);
			}
			else if(col[nx] == col[p]) isb = false;
		}
	}
	return min(c0,c1);
}

bool isBipartite(int v)
{
	isb = true;
	for(int a=0;a<v;a++)
	{
		if(col[a] == -1) 
		{
			if(vec[a].size() == 0) ans++;
			else ans+=traverse(a);
		}
	}
	return isb;
}

int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int v,e;
		cin>>v>>e;
		for(int a=0;a<v;a++) vec[a].clear(),col[a] = -1;
		ans = 0;
		for(int a=0;a<e;a++)
		{
			int t,f;
			cin>>t>>f;
			vec[t].push_back(f);
			vec[f].push_back(t);
		}
		if(!isBipartite(v))
		{
			printf("-1\n");
			continue;
		}
		printf("%d\n",ans);
	}
}
