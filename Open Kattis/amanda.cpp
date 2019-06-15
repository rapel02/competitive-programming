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

const int N = 200000;
int ans[N + 5];
int n,m;

vector<int> vec[N + 5],lef;
int visited[N + 5];
bool contradict = false;

int par[N + 5];

int trav,tot3;

void DFS(int idx) {
    int sz = vec[idx].size();
    visited[idx] = 1;
    trav++;
    if(ans[idx] == 0) tot3++;
    for(int i = 0;i < sz;i++){
        int nx = vec[idx][i];
        if(ans[nx] == -1){
            ans[nx] = 1 - ans[idx];
            DFS(nx);
        }
        else{
            if(ans[nx] != 1 - ans[idx]) contradict = true;
            else if(visited[nx] == 0) DFS(nx);
        }
    }
}

int main(){
    desperate_optimization(10);
    clock_t CLOCK;
    CLOCK = clock();
    cin>>n>>m;
    for(int i = 0; i <= n;i++) ans[i] = -1;
    while(m--){
        int u,v,c;
        cin>>u>>v>>c;
        if(c == 0) {
            if(ans[u] == 1 || ans[v] == 1) contradict = true;
            ans[u] = ans[v] = 0;
        }
        else if(c == 2) {
            if(ans[u] == 0 || ans[v] == 0) contradict = true;
            ans[u] = ans[v] = 1;
        }
        else {
            vec[u].PB(v);
            vec[v].PB(u);
        }
    }
    for(int i = 1; i <= n; i++) { //Assign Value to other Vertex
        if(visited[i] == 0 && ans[i] != -1) DFS(i);
    }
    int rect = 0;
    int res = 0;
    for(int i = 1; i <= n; i++) {
        if(ans[i] == 1) res++;
    }
    for(int i = 1; i <= n; i++) { //There are some vertex hasn't been assigned
        if(ans[i] == -1) {
            trav = 0, tot3 = 0;
            ans[i] = 0;
            DFS(i); //Check odd cycle
            res += min(trav - tot3,tot3);
        }
    }
    if(contradict == true) cout<<"impossible"<<endl;
    else{ 
        cout<<res<<endl;
    }
    cerr<<"PROCESSED TIME "<<(clock() - CLOCK) * 1.0 / (1.0 * CLOCKS_PER_SEC)<<endl;
    return 0;
}


