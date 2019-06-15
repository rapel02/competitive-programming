#include<bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
using namespace std;

vector<pair<int,int> > vec[255][2];
int flow[255][2][255][2];
pair<int,int> par[255][2];
queue<pair<int,int> > q;
bool vis[255][2];

void backtrack(int pos,int st)
{
	int prev = par[pos][st].ff;
	int prevst = par[pos][st].ss;
	if(prev==-1 && prevst==-1) return ;
	flow[prev][prevst][pos][st]--;
	flow[pos][st][prev][prevst]++;
	backtrack(prev,prevst);
}

int main()
{
	int n,m,k;
	while(scanf("%d",&n),n)
	{
		scanf("%d %d",&m,&k);
		memset(flow,0,sizeof(flow));
		for(int a=1;a<=n;a++) 
		{
			vec[0][1].pb(mp(a,0));
			vec[a][0].pb(mp(0,1));
			vec[a][0].pb(mp(a,1));
			vec[a][1].pb(mp(a,0));
			flow[a][0][a][1] = 1;
			flow[0][1][a][0] = 1;
		}
		for(int a=1;a<=m;a++) 
		{
			vec[a+101][0].pb(mp(a+101,1));
			vec[a+101][1].pb(mp(a+101,0));
			vec[250][0].pb(mp(a+101,1));
			vec[a+101][1].pb(mp(250,0));
			flow[a+101][1][250][0] = 1;
			flow[a+101][0][a+101][1] = 1;
		}
		for(int a=0;a<k;a++)
		{
			int i,x,y;
			scanf("%d %d %d",&i,&x,&y);
			x++;
			y++;
			vec[x][1].pb(mp(y+101,0));
			vec[y+101][0].pb(mp(x,1));
			flow[x][1][y+101][0] = 1;
		}
		flow[1][1][102][0] = 0;
		flow[102][0][1][1] = 1;
		flow[102][0][102][1] = 0;
		flow[102][1][102][0] = 0;
		flow[1][1][1][0] = 1;
		flow[1][0][1][1] = 0;
		int tot = 0;
		while(1)
		{
			while(!q.empty()) q.pop();
			memset(vis,false,sizeof(vis));
			q.push(mp(0,1));
			vis[0][1] = true;
			par[0][1] = mp(-1,-1);
			bool fin = false;
			while(!q.empty())
			{
				int pos = q.front().ff;
				int ssw = q.front().ss;
				//printf("%d %d\n",pos,ssw);
				q.pop();
				if(pos==250)
				{
					fin = true;
					break;
				}
				int sz = vec[pos][ssw].size();
				for(int a=0;a<sz;a++)
				{
					int nx = vec[pos][ssw][a].ff;
					int state = vec[pos][ssw][a].ss;
					if(vis[nx][state]==true) continue;
					if(flow[pos][ssw][nx][state]<=0) continue;
					vis[nx][state] = true;
					par[nx][state] = mp(pos,ssw);
					q.push(mp(nx,state));
				}
			}
			if(fin==false) break;
			tot++;
			backtrack(250,0);
		}
		printf("%d\n",tot);
		for(int a=0;a<255;a++) for(int b=0;b<2;b++) vec[a][b].clear();
	}
}
