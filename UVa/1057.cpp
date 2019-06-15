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

const int N = 100;
int arr[N + 5][N + 5];
int dist[N + 5][N + 5];
vector<int> vec[N + 5], vecrev[N + 5];

priority_queue<pair<int, pair<int,int> > >pq;

void hora(int tc) {
	int n,m;
	while(cin>>n>>m) {
		if(n + m == 0) break;
		for(int i = 0;i <= n;i++) for(int j = 0;j <= n;j++) dist[i][j] = 1e9;
		memset(arr, 0, sizeof arr);
		for(int i = 0;i < m;i++) {
			int u,v;
			cin>>u>>v;
			if(arr[u][v]) continue;
			arr[u][v] = 1;
			vec[u].PB(v);
			vecrev[v].PB(u);
		}
		dist[1][1] = 1;
		pq.push({-1,{1,1}});
		while(!pq.empty()) {
			int cost = -pq.top().FI;
			int u = pq.top().SE.FI;
			int v = pq.top().SE.SE;
			pq.pop();
			if(dist[u][v] != cost) continue;
			for(int i = 0;i < vec[u].size();i++) {
				int nx = vec[u][i];
				if(dist[nx][v] > cost + 1) {
					dist[nx][v] = cost + 1;
					pq.push({-dist[nx][v], {nx, v}});
				}
				if(arr[nx][v]) {
					if(dist[nx][nx] > cost + 1) {
						dist[nx][nx] = cost + 1;
						pq.push({-dist[nx][nx], {nx,nx}});
					}
				}
			}
			for(int i = 0;i < vecrev[v].size();i++) {
				int nx = vecrev[v][i];
				if(dist[u][nx] > cost + 1) {
					dist[u][nx] = cost + 1;
					pq.push({-dist[u][nx], {u, nx}});
				}
				if(arr[u][nx]) {
					if(dist[nx][nx] > cost + 1) {
						dist[nx][nx] = cost + 1;
						pq.push({-dist[nx][nx], {nx,nx}});
					}
				}
			}
		}
		for(int i = 0;i <= n;i++) vec[i].clear(), vecrev[i].clear();
		cout<<"Network "<<tc<<endl;
		if(dist[2][2] != 1e9) cout<<"Minimum number of nodes = "<<dist[2][2]<<endl;
		else cout<<"IMPOSSIBLE"<<endl;
		tc++;
		cout<<endl;
	}
}

int main(){
	desperate_optimization(10);
	int ntc = 1;
	//cin>>ntc;
	for(int tc = 1;tc <= ntc;tc++) hora(tc);
	return 0;
}


