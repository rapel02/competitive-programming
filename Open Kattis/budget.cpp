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

struct edge{
	int nx, rev;
	LL cap, tar;
};

const int M = 200, N = 20;
LL lo[M + 5][N + 5];
LL hi[M + 5][N + 5];
LL ro[M + 5], col[M + 5];

vector<edge> vec[M + N + 5];

void addEdge(int u,int v,LL cap) {
	edge tmp, tmp2;
	tmp.nx = v, tmp.cap = 0, tmp.tar = cap, tmp.rev = vec[v].size();
	tmp2.nx = u, tmp2.cap = cap, tmp2.tar = cap, tmp2.rev = vec[u].size();
	vec[u].PB(tmp), vec[v].PB(tmp2);
	return ;
}

int lv[M + N + 5], start[M + N + 5];

bool bfs(int src,int snk) {
	for(int i = 0;i <= snk;i++) lv[i] = -1, start[i] = 0;
	lv[src] = 0;
	queue<int> q;
	q.push(src);
	while(!q.empty()) {
		int pos = q.front();
//		cout<<"POS "<<pos<<endl;
		q.pop();
		for(int i = 0;i < vec[pos].size(); i++) {
			edge nx = vec[pos][i];
//			cout<<"NX "<<nx.nx<<" "<<nx.cap<<" "<<nx.tar<<endl;
			if(lv[nx.nx] != -1 || nx.cap == nx.tar) continue;
			lv[nx.nx] = lv[pos] + 1;
			q.push(nx.nx);
		}
	}
	return lv[snk] != -1;
}

LL sendflow(int pos,LL flow,int tar) {
	if(pos == tar) return flow;
	LL take = 0;
	for(;start[pos] < vec[pos].size();start[pos]++) {
		int i = start[pos];
		edge nx = vec[pos][i];
		if(lv[pos] + 1 == lv[nx.nx] && nx.cap != nx.tar) {
			LL curr = min(flow,nx.tar - nx.cap);
			LL tmp = sendflow(nx.nx,curr,tar);
			take += tmp;
			flow -= tmp;
			vec[pos][i].cap += tmp;
			vec[nx.nx][nx.rev].cap -= tmp;
		}
		if(flow == 0) break;
	}
	return take;
}

LL MAXFLOW(int src,int snk) {
	LL res = 0;
	LL f;
	while(bfs(src,snk)) {
		while(f = sendflow(src,1e18,snk) ) {
			res += f;
		}
	}
	return res;
}

void hora(int tc) {
	if(tc != 1) cout<<endl;
	int m,n;
	cin>>m>>n;
	LL sums = 0;
	for(int i = 1;i <= m;i++) {
		cin>>ro[i];
		sums += ro[i];
	}
	for(int i = 1;i <= n;i++) {
		cin>>col[i];
		sums -= col[i];
	}
	for(int i = 1;i <= m;i++) for(int j = 1;j <= n;j++) lo[i][j] = 0, hi[i][j] = 1e18;
	int q;
	cin>>q;
	while(q--) {
		int r,c;
		LL v;
		char op;
		cin>>r>>c>>op>>v;
		if(op == '>') v++;
		else if(op == '<') v--;
		if(op == '>' || op == '=') {
			if(r == 0 && c == 0) {
				for(int i = 1;i <= m;i++) for(int j = 1;j <= n;j++) lo[i][j] = max(lo[i][j], v);
			}
			else if(r == 0) {
				for(int i = 1;i <= m;i++) lo[i][c] = max(lo[i][c], v);
			}
			else if(c == 0) {
				for(int i = 1;i <= n;i++) lo[r][i] = max(lo[r][i], v);
			}
			else lo[r][c] = max(lo[r][c], v);
		}
		if(op == '<' || op == '=') {
			if(r == 0 && c == 0) {
				for(int i = 1;i <= m;i++) for(int j = 1;j <= n;j++) hi[i][j] = min(hi[i][j], v);
			}
			else if(r == 0) {
				for(int i = 1;i <= m;i++) hi[i][c] = min(hi[i][c], v);
			}
			else if(c == 0) {
				for(int i = 1;i <= n;i++) hi[r][i] = min(hi[r][i], v);
			}
			else hi[r][c] = min(hi[r][c], v);
		}
	}
	bool bisa = (sums == 0);
	for(int i = 1;i <= m;i++) for(int j = 1;j <= n;j++) {
		ro[i] -= lo[i][j];
		col[j] -= lo[i][j];
		if(ro[i] < 0 || col[j] < 0 || lo[i][j] > hi[i][j]) bisa = false;
	}
	if(bisa == false) {
		cout<<"IMPOSSIBLE"<<endl;
		return ;
	}
	int SRC = 0, SNK = m + n + 1;
	for(int i = 1;i <= m;i++) {
//		cout<<"ADD1 "<<0<<" "<<i<<" "<<ro[i]<<endl;
		addEdge(0,i, ro[i]);
	}
	for(int i = 1;i <= n;i++) {
//		cout<<"ADD2 "<<i<<" "<<SNK<<" "<<col[i]<<endl;
		addEdge(m + i, SNK, col[i]);
	}
	for(int i = 1;i <= m;i++) for(int j = 1;j <= n;j++) {
//		cout<<"ADD3 "<<i<<" "<<j<<" "<<hi[i][j] - lo[i][j]<<endl;
		addEdge(i,m + j, hi[i][j] - lo[i][j]);
	}
	LL tot = MAXFLOW(SRC,SNK);
//	cout<<"MAXFLOW "<<tot<<endl;
	for(auto x: vec[0]) if(x.tar != x.cap) bisa = false;
	for(int i = 1;i <= n;i++) if(vec[i + m][0].tar != vec[i + m][0].cap) bisa = false;
	if(bisa == false) cout<<"IMPOSSIBLE"<<endl;
	else {
//		cout<<"RESULT: "<<endl;
		for(int i = 1;i <= m;i++) {
			for(int j = 1;j <= n;j++) {
				if(j != 1) cout<<" ";
				cout<<lo[i][j] + vec[i][j].cap;
			}
			cout<<endl;
		}
	}
	for(int i = SRC;i <= SNK;i++) vec[i].clear();
}

int main(){
	desperate_optimization(10);
	int ntc = 1;
	cin>>ntc;
	for(int tc = 1;tc <= ntc;tc++) hora(tc);
	return 0;
}


