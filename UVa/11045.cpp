#include<bits/stdc++.h>
#define pb push_back
using namespace std;

vector<int> vec[60];

int flow[60][60];
int par[60];
bool vis[60];


int conv(string a)
{
	if(a=="XS") return 40;
	if(a=="S") return 41;
	if(a=="M") return 42;
	if(a=="L") return 43;
	if(a=="XL") return 44;
	if(a=="XXL") return 45;
}

string in;

queue<int> q;

void backtrack(int pos)
{
	if(par[pos]==-1) return ;
	//printf("%d ",pos);
	flow[par[pos]][pos]--;
	flow[pos][par[pos]]++;
	backtrack(par[pos]);
}

int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		int N,M;
		scanf("%d %d",&N,&M);
		memset(flow,0,sizeof(flow));
		for(int a=1;a<=M;a++) vec[0].pb(a),flow[0][a] = 1;
		for(int a=1;a<=M;a++)
		{
			cin>>in;
			int ch = conv(in);
			vec[a].pb(ch);
			vec[ch].pb(a);
			flow[a][ch] = 1;
			cin>>in;
			ch = conv(in);
			vec[a].pb(ch);
			vec[ch].pb(a);
			flow[a][ch] = 1;
		}
		for(int a=40;a<=45;a++) vec[a].pb(50),flow[a][50] = N/6;
		int tot = 0;
		while(1)
		{
			//printf("\nFlow %d\n",tot);
			while(!q.empty()) q.pop();
			q.push(0);
			memset(vis,false,sizeof(vis));
			memset(par,-1,sizeof(par));
			vis[0] = true;
			par[0] = -1;
			while(!q.empty())
			{
				int pos = q.front();
				//printf("%d\n",pos);
				q.pop();
				if(pos==50) break;
				int sz = vec[pos].size();
				for(int a=0;a<sz;a++)
				{
					int nx = vec[pos][a];
					if(flow[pos][nx]<=0) continue;
					if(vis[nx]==true)continue;
					vis[nx] = true;
					par[nx] = pos;
					q.push(nx);
				}
			}
			//printf("END FLOW\n");
			if(par[50]==-1) break;
			else
			{
				tot++;
				backtrack(50);
			}
		}
		if(M==tot) printf("YES\n");
		else printf("NO\n");
		for(int a=0;a<60;a++) vec[a].clear();
	}
}
