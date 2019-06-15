#include<bits/stdc++.h>
using namespace std;

struct edge{
    int nx;
    int flow;
    int cost;
    int revidx;
};

vector<edge> vec[2500];

void addEdge(int u,int v,int cap,int cost = 0) {
    edge tmp, tmp2;
    tmp.nx = v;
    tmp.flow = 1;
    tmp.cost = -cost;
    tmp.revidx = vec[v].size();
    tmp2.nx = u;
    tmp2.flow = 0;
    tmp2.cost = (cost == 0)?1e8:cost;
    tmp2.revidx = vec[u].size();
    vec[u].push_back(tmp);
    vec[v].push_back(tmp2);
}

int par[2500], dist[2500];
int id[2500];
int fin[2500];
int f = 0;
int states[2500];
deque<int> dq;

int bellman(int src,int snk) {
    for(int i = 0;i <= snk;i++) par[i] = -1, dist[i] = 1e9, states[i] = 2;
    dist[0] = 0, par[0] = 0;
    dq.push_back(0);
    while(!dq.empty()) {
    	int u = dq.front();
    	dq.pop_front();
    	states[u] = 0;
    	int j = u;
    	for(int k =0;k < vec[j].size();k++) {
            edge nx = vec[j][k];
            if(dist[nx.nx] > dist[j] + nx.cost && nx.flow != 0) {
                dist[nx.nx] = dist[j] + nx.cost;
                par[nx.nx] = j;
                id[nx.nx] = k;
                if(states[nx.nx] == 2) {
                	states[nx.nx] = 1;
                	dq.push_back(nx.nx);
				}
				else if(states[nx.nx] == 0) {
					states[nx.nx] = 1;
					dq.push_front(nx.nx);
				}
            }
        }
	}
    return dist[snk];
}

void backtrack(int idx) {
    if(idx == 0) return ;
    int pr = par[idx];
    int idd = id[idx];
    fin[idx] = pr;
    f = min(f,vec[pr][idd].flow);
    backtrack(pr);
    vec[pr][idd].flow -= f;
    vec[idx][vec[pr][idd].revidx].flow += f;
}

int MCMF(int src,int snk) {
    int tot = 0;
    memset(fin,-1,sizeof fin);
    while(1) {
        int res = bellman(src,snk);
        if(res >= 0) return tot;
        tot -= res;
        f = 1e9;
        backtrack(snk);     
    }
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int m,n,k;
    cin>>m>>n>>k;
    int src = 0, snk = m + n + 1;
    for(int i = 1;i <= n;i++) addEdge(src,i,1);
    for(int i = 1;i <= m;i++) addEdge(n + i, snk, 1);
    while(k--) {
        int u,v,ct;
        cin>>u>>v>>ct;
        addEdge(u,n + v,1,ct);
    }
    int res = MCMF(src,snk);
    cout<<res<<endl;
    vector<pair<int,int> > vet;
    for(int i = n + 1;i <= n + m;i++) {
        if(fin[i] != -1) vet.push_back(make_pair(fin[i],i - n));
    }
    cout<<vet.size()<<endl;
    for(int i = 0;i < vet.size();i++) {
        cout<<vet[i].first<<" "<<vet[i].second<<endl;
    }
}
