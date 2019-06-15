#include <stdio.h>
#include <iostream>
#include <sstream>

#include <algorithm>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <utility>

#include <math.h>
#include <complex>

#include <assert.h>
#include <time.h>

#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <bitset>
#define FI first
#define SE second
#define MP make_pair
#define PB push_back
#define endl '\n'
using namespace std;

void desperate_optimization(int precision){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(precision);
}

typedef long long ll;
typedef unsigned long long ull;

int SRC, SNK;
const int N = 250;

struct edge {
    ll nxt;
    ll cost;
    ll flow;
    ll reverseidx;
    edge(){}
    edge(ll nxt,ll cost,ll flow,ll reverseidx) {
        this->nxt = nxt;
        this->cost = cost;
        this->flow = flow;
        this->reverseidx = reverseidx;
    }
};

vector<edge> vec[N + 5];

ll dist[N + 5];
pair<ll,ll> par[N + 5];
int n, m;

bool bellmanFord() {
    for(int i = 0; i < n; i++) par[i] = MP(-1,-1), dist[i] = 1e18;
    par[SRC] = MP(SRC,0), dist[SRC] = 0;
    for(int i = 0; i < n - 1; i++) {
        bool chg = false;
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < vec[j].size();k++) {
                edge nx = vec[j][k];
                if(nx.flow != 0 && dist[j] != 1e18 && dist[nx.nxt] > dist[j] + nx.cost) {
                    dist[nx.nxt] = dist[j] + nx.cost;
                    par[nx.nxt] = MP(j,k);
                    chg = true;
                }
            }
        }
        if(chg == false) break;
    }
    return par[SNK].FI != -1;
}

ll f = 1e18;

void backtrack(int pos) {
    if(pos == SRC) return ;
    int prev = par[pos].FI;
    int idx = par[pos].SE;
    f = min(f,vec[prev][idx].flow);
    backtrack(prev);
    vec[prev][idx].flow -= f;
    vec[pos][vec[prev][idx].reverseidx].flow += f;
}

int main() {
    cin>>n>>m>>SRC>>SNK;
    for(int i = 0; i < m; i++) {
        int u,v,flow,cost;
        cin>>u>>v>>flow>>cost;
        vec[u].PB(edge(v,cost,flow,vec[v].size()));
        vec[v].PB(edge(u,-cost,0,vec[u].size() - 1));
    }
    ll cost = 0;
    ll tot = 0;
    while(bellmanFord() == true) {
        f = 1e18;
        backtrack(SNK);
        cost += f * dist[SNK];
        tot += f;
    }
    cout<<tot<<" "<<cost<<endl;
}