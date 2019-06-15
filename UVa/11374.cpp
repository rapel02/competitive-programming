#include<bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
using namespace std;

const int MAXN = 550;

int dist[MAXN][2];
pair<int,int> par[MAXN][2];
vector<pair<int,int> >vec[MAXN][2];

priority_queue<pair<int,pair<int,int> > > pq;

const int INF = 1e+9;
int used = -1;

stack<int> path;

void backtrack(int pos,int state)
{
	path.push(pos);
	int prevpos = par[pos][state].ff;
	int prevstate = par[pos][state].ss;
	if(prevpos == -1) return ;
	if(prevstate != state) used = prevpos;
	backtrack(prevpos,prevstate);
}

int main()
{
	ios_base::sync_with_stdio(false);
	int N,S,E;
	bool cons = true;
	while(cin>>N>>S>>E)
	{
		if(!cons) cout<<endl;
		cons = false;
		used = -1;
		for(int a=0;a<=N;a++) 
			for(int b=0;b<2;b++) 
				vec[a][b].clear(),dist[a][b] = INF,par[a][b] = mp(-1,-1);
		int m;
		cin>>m;
		for(int a=0;a<m;a++)
		{
			int f,t,c;
			cin>>f>>t>>c;
			vec[f][0].pb(mp(t,c));
			vec[t][0].pb(mp(f,c));
		}
		cin>>m;
		for(int a=0;a<m;a++)
		{
			int f,t,c;
			cin>>f>>t>>c;
			vec[f][1].pb(mp(t,c));
			vec[t][1].pb(mp(f,c));
		}
		pq.push(mp(0,mp(S,0)));
		dist[S][0] = 0;
		while(!pq.empty())
		{
			int val = -pq.top().ff;
			int pos = pq.top().ss.ff;
			int state = pq.top().ss.ss;
			pq.pop();
			if(state == 0)
			{
				int sz = vec[pos][1].size();
				for(int a=0;a<sz;a++)
				{
					int nx = vec[pos][1][a].ff;
					int ct = vec[pos][1][a].ss;
					if(dist[nx][1] > val + ct)
					{
						dist[nx][1] = val + ct;
						par[nx][1] = mp(pos,0);
						pq.push(mp(-dist[nx][1],mp(nx,1)));
					}
				}
			}
			int sz = vec[pos][0].size();
			for(int a=0;a<sz;a++)
			{
				int nx = vec[pos][0][a].ff;
				int ct = vec[pos][0][a].ss;
				if(dist[nx][state] > val + ct)
				{
					dist[nx][state] = val + ct;
					par[nx][state] = mp(pos,state);
					pq.push(mp(-dist[nx][state],mp(nx,state)));
				}
			}
		}
		long long ans = -1;
		if(dist[E][1] > dist[E][0]) ans = dist[E][0],backtrack(E,0);
		else ans = dist[E][1],backtrack(E,1);
		bool isf = true;
		while(!path.empty())
		{
			if(isf==false) cout<<" ";
			isf = false;
			cout<<path.top();
			path.pop();
		}
		if(used == -1) cout<<"\nTicket Not Used\n";
		else cout<<"\n"<<used<<"\n";
		cout<<ans<<endl;
	}
}
