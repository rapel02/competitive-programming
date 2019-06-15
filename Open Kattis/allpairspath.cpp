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

const int N = 150;

LL dist[N + 5][N + 5];
LL dist2[N + 5][N + 5];

int main(){
    desperate_optimization(10);
    clock_t CLOCK;
    CLOCK = clock();
    int n,m,q;
    while(cin>>n>>m>>q){
        if(n + m + q == 0) break;
        for(int i = 0; i < n;i++) for(int j=0;j<n;j++) dist[i][j] = ((i == j)?0:1e12);
        for(int i = 0; i < m;i++) {
            LL u,v,x;
            cin>>u>>v>>x;
            dist[u][v] = min(dist[u][v],x);
        }
        for(int k = 0;k < n;k++) {
            for(int i = 0; i < n;i++){
                for(int j = 0;j < n;j++) if(dist[i][k] != 1e12 && dist[k][j] != 1e12) dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
            }
        }   
        for(int i = 0; i < n;i++){
            for(int j = 0;j < n;j++) {
                for(int k = 0;k < n;k++) {
                    if(dist[i][k] < 1e6 && dist[k][j] < 1e6 && dist[k][k] < 0) dist[i][j] = -1e7;
                }
            }
        }
        while(q--) {
            int u,v;
            cin>>u>>v;
            if(dist[u][v] > 1e6) cout<<"Impossible"<<endl;
            else {
                if(dist[u][v] < - 1e6) cout<<"-Infinity"<<endl;
                else cout<<dist[u][v]<<endl;
            }
        }
        cout<<endl;

    }
    cerr<<"PROCESSED TIME "<<(clock() - CLOCK) * 1.0 / (1.0 * CLOCKS_PER_SEC)<<endl;
    return 0;
}


