#include <stdio.h>
#include <iostream>
#include <sstream>
#include <iomanip>

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

typedef long long LL;
typedef unsigned long long ULL;

void desperate_optimization(int precision){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(precision);
}

const int N = 1000;
vector<pair<int,int> >vec[N + 5], vec2[N + 5];
priority_queue<pair<pair<int,int>,pair<int,int> > > pq;
int par[N + 5];
int bef[N + 5];
int path[N + 5];
int mark[N + 5];

int find(int u) {
    if(u == par[u]) return u;
    return par[u] = find(par[u]);
}

int main(){
    desperate_optimization(10);
    clock_t CLOCK;
    CLOCK = clock();
    int n,m;
    cin>>n>>m;
    for(int i = 0;i < m;i++) {
        int u,v;
        int ct;
        cin>>u>>v>>ct;
        pq.push(MP(MP(ct,i),MP(u,v)));
        vec2[u].PB(MP(v,i));
        vec2[v].PB(MP(u,i));
        mark[i] = -1;
    }
    for(int i = 0;i < n;i++) par[i] = i, bef[i] = -1;
    while(!pq.empty()) {
        int idx = pq.top().FI.SE;
        int u = pq.top().SE.FI;
        int v = pq.top().SE.SE;
        pq.pop();
        if(find(u) != find(v)) {
            par[find(u)] = find(v);
            vec[u].PB(MP(v,idx));
            vec[v].PB(MP(u,idx));
            mark[idx] = 1;
        }
        if(find(0) == find(n - 1)) break;
    }
    queue<int> q;
    q.push(0);
    bef[0] = 0;
    while(!q.empty()) {
        int idx = q.front();
        q.pop();
        for(int i = 0;i < vec[idx].size();i++) {
            int nx = vec[idx][i].FI;
            int id = vec[idx][i].SE;
            if(bef[nx] != -1) continue;
            bef[nx] = idx;
            path[nx] = id;
            q.push(nx);
        }
    }
    int now = n - 1;
    for(int i = 0;i < vec2[now].size();i++) mark[vec2[now][i].SE] = 0;
    while(now != 0) {
        mark[path[now]] = 2;
        int rem = path[now];
        now = bef[now];
        for(int i = 0;i < vec2[now].size();i++) {
            int id = vec2[now][i].SE;
            if(rem != id) mark[id] = 0;
        }
    }
    int ada = 0;
    for(int i = 0; i < m;i++) {
        if(mark[i] == 0) {
            cout<<i<<" ";
            ada = 1;
        }
    }
    if(ada == 0) cout<<"none";
    cout<<endl;
    cerr<<"PROCESSED TIME "<<(clock() - CLOCK) * 1.0 / (1.0 * CLOCKS_PER_SEC)<<endl;
    return 0;
}


