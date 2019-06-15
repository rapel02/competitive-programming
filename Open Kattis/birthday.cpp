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

vector<pair<int,int> > vec[105];
int num[105], lo[105];
int instk[105];
stack<int> stk;
int numscc, ctr;
int p,c;

void SCC(int idx,int err) {
	num[idx] = lo[idx] = ++ctr;
	instk[idx] = 1;
	stk.push(idx);
	for(int i = 0;i < vec[idx].size();i++) {
		int nx = vec[idx][i].FI;
		int id = vec[idx][i].SE;
		if(id == err) continue;
		if(num[nx] == 0) {
			SCC(nx,err);
			lo[idx] = min(lo[idx], lo[nx]);
		}
		else if(instk[nx] == 1) {
			lo[idx] = min(lo[idx],num[nx]);
		}
	}
	if(lo[idx] == num[idx]) {
		numscc++;
		while(1) {
			int v = stk.top();
			stk.pop();
			instk[v] = 0;
			if(v == idx) break;
		}
	}
}

bool solve(int idx) {
	for(int i = 0;i < p;i++) num[i] = lo[i] = instk[i] = 0;
	numscc = 0, ctr = 0;
	SCC(0,idx);
	return (numscc == 1) && (ctr == p);
}

void hora(int tc) {
	while(cin>>p>>c) {
		if(p + c == 0) break;
		for(int i = 0;i < c;i++) {
			int u,v;
			cin>>u>>v;
			vec[u].PB({v,i}), vec[v].PB({u,i});
		}
		bool bisa = true;
		for(int i = 0;i < c;i++) {
			bisa &= solve(i);
		}
		cout<<((bisa == true)?"No":"Yes")<<endl;
		for(int i = 0;i < p;i++) vec[i].clear();
	}
}

int main(){
	desperate_optimization(10);
	int ntc = 1;
	//cin>>ntc;
	for(int tc = 1;tc <= ntc;tc++) hora(tc);
	return 0;
}


