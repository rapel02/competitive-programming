#include<bits/stdc++.h>
#define pb push_back
using namespace std;

bool topo;
int stt[1000005];
vector<int> vec[1000005];
stack<int> s;

void toposort(int a)
{
	stt[a] = 1;
	for(int b=0;b<vec[a].size();b++)
	{
		if(stt[vec[a][b]]==1)
		{
			topo = false;
			return ;
		}
		else if(stt[vec[a][b]]==0)
		{
			stt[vec[a][b]] = 1;
			toposort(vec[a][b]);
		}
	}
	stt[a] = 2;
	s.push(a);
	return ;
}

int main()
{
	int n, m;
	while(1)
	{
		scanf("%d %d",&n,&m);
		if(n==0 && m==0) break;
		topo = true;
		memset(stt,0,sizeof(stt));
		for(int a=0;a<m;a++)
		{
			int t,f;
			scanf("%d %d",&t,&f);
			vec[t].pb(f);
		}
		for(int a=n;a>=1;a--)
		{
			if(stt[a]==0)
			{
				toposort(a);
			}
			vec[a].clear();
		}
		if(topo==false) printf("IMPOSSIBLE\n");
		else
		{
			while(!s.empty()){
				printf("%d\n",s.top());
				s.pop();
			}
		}
		while(!s.empty()) s.pop();
	}
}
