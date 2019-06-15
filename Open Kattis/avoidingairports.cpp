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
int n,m;

struct edge{
    int u,v;
    LL s,e;
};

vector<edge> edges;

bool cmp(edge A,edge B) { //prioritaskan start paling awal, kalau ada yang sama end paling awal
    if(A.s != B.s) return A.s < B.s;
    return A.e < B.e;
}

const int N = 1e6;
const LL INF = 1e18;
vector<LL> M[N + 5],C[N + 5];
priority_queue<pair<LL,LL> > pq[N + 5];
vector<pair<LL,LL> > TMP[N + 5];
LL DP[N + 5];
//int pos[N + 5];

void pendinginsert(int idx,LL res,LL end) {
    pq[idx].push(MP(-2 * end,res + end * end) );
}

bool bad(int idx, int l1,int l2,int l3) {
    return (C[idx][l2] - C[idx][l1]) * (M[idx][l3] - M[idx][l1]) < (C[idx][l3] - C[idx][l1]) * (M[idx][l2] - M[idx][l1]);
}

LL funct(int idx,int pos,LL time) {
    return M[idx][pos] * time + C[idx][pos];
}

LL query(int idx,LL time) {
    while(!pq[idx].empty() && pq[idx].top().FI > -2 * time) {
        //insert
        pair<LL,LL> top = pq[idx].top();
        pq[idx].pop();
        M[idx].PB(top.FI);
        C[idx].PB(top.SE);
        while(M[idx].size() >= 3 && bad(idx, M[idx].size()- 3, M[idx].size() - 2, M[idx].size() - 1) ) {
            M[idx].erase(M[idx].end() - 2);
            C[idx].erase(C[idx].end() - 2);
        }
    }
    if(M[idx].size() == 0) return 3LL * INF;
    int lo = 0;
    int hi = M[idx].size() - 1;
    while(hi - lo > 350) {
        int mid1 = lo + (hi - lo) / 3;
        int mid2 = hi - (hi - lo) / 3;
        if(funct(idx,mid1,time) < funct(idx,mid2,time)) hi = mid2 - 1;
        else lo = mid1 + 1;
    }
    LL ans = INF;
    for(int i = lo;i <= hi;i++) ans = min(ans,funct(idx,i,time));
    return ans;
    // if(pos[idx] >= M[idx].size()) pos[idx] = M[idx].size() - 1;
    // while(pos[idx] < M[idx].size() - 1 && M[idx][pos[idx] + 1] * time + C[idx][pos[idx] + 1] <=  M[idx][pos[idx]] * time + C[idx][pos[idx]]) pos[idx]++;
    // return M[idx][pos[idx]] * time + C[idx][pos[idx]];
}

LL BF(edge tmp) {
    int u = tmp.u;
    int v = tmp.v;
    LL start = tmp.s;
    LL end = tmp.e;
    LL res = INF; 
    for(int i = 0;i < TMP[u].size();i++) {
        pair<LL,LL> te = TMP[u][i];
        if(te.SE <= start) {
            res = min(res,te.FI + abs(te.SE - start) * abs(te.SE - start));
        }
    }
    TMP[v].PB(MP(res,end)); //emosi, time sampe
    return res;
}

int main(){
    desperate_optimization(10);
    clock_t CLOCK;
    CLOCK = clock();
    for(int i = 0;i <= N;i++) DP[i] = INF;
    cin>>n>>m;
    edge tmp;
    tmp.u = tmp.v = 1;
    tmp.s = tmp.e = 0;
    edges.PB(tmp);
    DP[0] = 0;
    M[1].PB(-2 * tmp.e);
    C[1].PB(DP[0] + tmp.e * tmp.e);
    TMP[1].PB(MP(0,0));
    for(int i = 1;i <= m;i++) {
        cin>>tmp.u>>tmp.v>>tmp.s>>tmp.e;
        edges.PB(tmp);
    }
    sort(edges.begin(),edges.end(),cmp);
    LL time = INF;
    for(int i = 1;i <= m;i++) {
        edge now = edges[i];
        int u = now.u;
        int v = now.v;
        LL start = now.s;
        LL end = now.e;
        DP[i] = min(DP[i],query(u,start) + start * start);
        if(v == n) time = min(time,DP[i]);
        pendinginsert(v,DP[i],end);
    }
    cout<<time<<endl;
    cerr<<"PROCESSED TIME "<<(clock() - CLOCK) * 1.0 / (1.0 * CLOCKS_PER_SEC)<<endl;
    return 0;
} 