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

const int N = 100000;

int par[N + 5];

vector<pair<ll,int> > sbX,sbY,sbZ;

int find(int x) {
    if(x == par[x]) return x;
    return par[x] = find(par[x]);
}

int posX[N + 5], posY[N + 5], posZ[N + 5];
priority_queue<pair<ll,pair<ll,ll> > > pq;

int main() {
    desperate_optimization(10);
    int n;
    cin>>n;
    for(int i = 0; i < n; i++) {
        ll x,y,z;
        cin>>x>>y>>z;
        sbX.PB(MP(x,i));
        sbY.PB(MP(y,i));
        sbZ.PB(MP(z,i));
        par[i] = i;
    }
    par[n] = n;
    sort(sbX.begin(),sbX.end());
    sort(sbY.begin(),sbY.end());
    sort(sbZ.begin(),sbZ.end());
    for(int i = 0;i < sbX.size(); i++) {
        posX[sbX[i].SE] = i;
        posY[sbY[i].SE] = i;
        posZ[sbZ[i].SE] = i;
    }
    ll res = 0;
    pq.push(MP(0,MP(0,n)));
    while(!pq.empty()) {
        ll cost = -pq.top().FI;
        int u = pq.top().SE.FI;
        int v = pq.top().SE.SE;
        pq.pop();
        if(find(u) == find(v)) continue;
        res += cost;
        par[find(u)] = find(v);
        if(posX[u] != 0) {
            if(find(u) != find(sbX[posX[u] - 1].SE)) {
                pq.push(MP(-abs(sbX[posX[u]].FI - sbX[posX[u] - 1].FI), MP(sbX[posX[u] - 1].SE, u)));
            }
        }
        if(posX[u] != n - 1) {
            if(find(u) != find(sbX[posX[u] + 1].SE)) {
                pq.push(MP(-abs(sbX[posX[u]].FI - sbX[posX[u] + 1].FI), MP(sbX[posX[u] + 1].SE, u)));
            }  
        }
        if(posY[u] != 0) {
            if(find(u) != find(sbY[posY[u] - 1].SE)) {
                pq.push(MP(-abs(sbY[posY[u]].FI - sbY[posY[u] - 1].FI), MP(sbY[posY[u] - 1].SE , u)));
            }
        }
        if(posY[u] != n-1) {
            if(find(u) != find(sbY[posY[u] + 1].SE)) {
                pq.push(MP(-abs(sbY[posY[u]].FI - sbY[posY[u] + 1].FI), MP(sbY[posY[u] + 1].SE , u)));
            }
        }
        if(posZ[u] != 0) {
            if(find(u) != find(sbZ[posZ[u] - 1].SE)) {
                pq.push(MP(-abs(sbZ[posZ[u]].FI - sbZ[posZ[u] - 1].FI), MP(sbZ[posZ[u] - 1].SE , u)));
            }
        }
        if(posZ[u] != n-1) {
            if(find(u) != find(sbZ[posZ[u] + 1].SE)) {
                pq.push(MP(-abs(sbZ[posZ[u]].FI - sbZ[posZ[u] + 1].FI), MP(sbZ[posZ[u] + 1].SE , u)));
            }
        }
    }
    cout<<res<<endl;
}