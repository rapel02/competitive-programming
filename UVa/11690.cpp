#include<bits/stdc++.h>
#define pb push_back
using namespace std;

vector<int> vec[10005];
int arr[10005];
queue<int> q;
bool vis[10005];


int main()
{
	int test;
	int n,m,to,fro;
	scanf("%d",&test);
	while(test--)
	{
		bool ada=true;
		memset(vis,false,sizeof(vis));
		scanf("%d %d",&n,&m);
		for(int a=0;a<n;a++)
			scanf("%d",&arr[a]);
		for(int a=0;a<m;a++)
		{
			scanf("%d %d",&to,&fro);
			vec[to].pb(fro);
			vec[fro].pb(to);
		}
		for(int a=0;a<n;a++)
		{
			if(vis[a]==false)
			{
				q.push(a);
				vis[a]=true;
				int tot=0;
				while(!q.empty())
				{
					int ff=q.front();
					tot+=arr[ff];
					q.pop();
					for(int b=0;b<vec[ff].size();b++)
					{
						if(vis[vec[ff][b]]==false)
						{
							q.push(vec[ff][b]);
							vis[vec[ff][b]]=true;
						}
					}
				}
				if(tot!=0) ada=false;
			}
		}
		if(ada==false) printf("IMPOSSIBLE\n");
		else printf("POSSIBLE\n");
	}
}
