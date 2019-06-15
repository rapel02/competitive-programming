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

const int N = 500;

ll dist[N + 5][N + 5];
ll ndist[N + 5][N + 5];
ll insp[N + 5];

pair<ll,pair<ll,ll> > p[N + 5];

int par[N + 5];
int vis[N + 5];
vector<int> adj[N + 5];
int n,m ;

int augment(int idx) {
    if(vis[idx] == 1) return 0;
    vis[idx] = 1;
    for(int i = 0 ; i < adj[idx].size(); i++) {
        int nx = adj[idx][i];
        if(par[nx] == -1 || augment(par[nx])) {
            par[nx] = idx;
            return 1;
        }
    }
    return 0;
}

int MCBM() {
    int ans = 0;
    memset(par,-1,sizeof(par));
    for(int i = 1;i <= m;i++) {
        memset(vis,0,sizeof(vis));
        ans += augment(i);
    }
    return ans;
}

int main() {
    desperate_optimization(10);
    cin>>n>>m;
    for(int i = 1; i <= n; i++) cin>>insp[i];
    for(int i = 1; i <= n; i++) 
        for(int j = 1; j <= n; j++) {
            cin>>dist[i][j];
            ndist[i][j] = dist[i][j];
            if(i != j) ndist[i][j] += insp[j];
        }
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) ndist[i][j] = min(ndist[i][j],ndist[i][k] + ndist[k][j]);
        }
    }
    for(int i = 1; i  <= m; i++) {
        cin>>p[i].SE.FI>>p[i].SE.SE>>p[i].FI;
    }
    sort(p + 1, p + m + 1);
    for(int i = 1; i <= m; i++) {
        for(int j = i + 1;j <= m; j++) {
            if(p[i].FI + dist[p[i].SE.FI][p[i].SE.SE] + insp[p[i].SE.SE] + ndist[p[i].SE.SE][p[j].SE.FI] <= p[j].FI) {
                adj[i].push_back(j);
            }
        }
    }
    cout<<m - MCBM()<<endl;
    return 0;
}