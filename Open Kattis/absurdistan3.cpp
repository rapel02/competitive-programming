////////////////////////////////////////////
///                                      ///
///         Template ver. 1 rapel        ///
/// Fear is Temporary, Regret is Forever ///
///          Must Try and Get AC         ///
///                                      ///
////////////////////////////////////////////
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
//#include <chrono>
//#include <random>

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
#define PF push_front
#define POB pop_back
#define POF pop_front
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

const int N = 1e5 + 5;
const int INF = 1e9;
vector<int> adj[N];
int n;

bool vis[N];
int matchU[N], matchV[N], dist[N];

bool bfs(){
	queue<int> q;
	for(int i=1; i<=n; i++){
		if(matchU[i]==0) dist[i]=0, q.push(i);
		else dist[i]=INF;
	}
	dist[0]=INF;
	while(!q.empty()){
		int u = q.front(); 
		q.pop();
		if(dist[u] < dist[0]){
		for(auto v: adj[u]){
			if(dist[matchV[v]]==INF){
				dist[matchV[v]] = dist[u]+1;
				q.push(matchV[v]);
				}
			}
		}
	}
	return dist[0]!=INF;
}

bool dfs(int u){
	if(u!=0){
		for(auto v: adj[u]){
			if(dist[matchV[v]] == dist[u]+1){
				if(dfs(matchV[v])){
					matchV[v] = u; matchU[u] = v;
					return true;
				}
			}
		}
		dist[u]=INF;
		return false;	
	}
	return true;
}

int solve(){
	for(int i=0;i<N;i++)
		matchU[i]=matchV[i]=dist[i]=0;
	int ret = 0;
	while(bfs()){
		for(int i=1;i<=n;i++){
			if(matchU[i]==0 && dfs(i)) ret++;
		}
	}
	return ret;
}

vector<pair<int,int> >edges;

void hora(int tc) {
	cin>>n;
	edges.PB({0,0});
	for(int i = 1;i <= n;i++) {
		int u,v;
		cin>>u>>v;
		adj[u].PB(i), adj[v].PB(i);
		edges.PB({u,v});
	}
	int ww = solve();
	for(int i = 1;i <= n;i++) {
		int x = matchU[i];
		if(edges[x].FI == i) cout<<edges[x].FI<<" "<<edges[x].SE<<endl;
		else cout<<edges[x].SE<<" "<<edges[x].FI<<endl;
	}
}

int main(){
	desperate_optimization(10);
	int ntc = 1;
	//cin>>ntc;
	for(int tc = 1;tc <= ntc;tc++) hora(tc);
	return 0;
}


