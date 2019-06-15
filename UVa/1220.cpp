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

map<string,int> ms;

const int N = 200;
int dp[2][N + 5];
int sama[2][N + 5];
vector<int> vec[N + 5];
int k = 0;

int getidx(string &s) {
	if(ms[s] == 0) ms[s] = ++k;
	return ms[s];
}

void solve(int idx,int pre) {
	dp[0][idx] = dp[1][idx] = 0;
	sama[0][idx] = sama[1][idx] = 0;
	dp[1][idx] = 1;
	for(int i = 0;i < vec[idx].size();i++) {
		int nx = vec[idx][i];
		if(nx == pre) continue;
		solve(nx,idx);
		dp[1][idx] += dp[0][nx];
		if(sama[0][nx] == 1) sama[1][idx] = 1;
		dp[0][idx] += max(dp[1][nx],dp[0][nx]);
		if(dp[1][nx] == dp[0][nx]) sama[0][idx] = 1;
		else if(dp[1][nx] > dp[0][nx]) sama[0][idx] = max(sama[0][idx],sama[1][nx]);
		else sama[0][idx] = max(sama[0][idx],sama[0][nx]);
	}
	//if(dp[0][idx] == dp[1][idx]) sama[0][idx] = sama[1][idx] = 1;
}

void hora(int tc) {
	int n;
	while(cin>>n) {
		if(n == 0) break;
		ms.clear();
		string nm;
		cin>>nm;
		int root = getidx(nm);
		for(int i = 1;i < n;i++) {
			string nm1,nm2;
			cin>>nm1>>nm2;
			int u = getidx(nm1);
			int v = getidx(nm2);
			vec[u].PB(v);
			vec[v].PB(u);
		}
		solve(1,1);
		int res = max(dp[0][1],dp[1][1]);
		int idx = root;
		if(dp[0][idx] == dp[1][idx]) sama[0][idx] = sama[1][idx] = 1;
		cout<<res<<" ";
		if(res == dp[0][1]) cout<<((sama[0][1]==0)?"Yes":"No")<<endl;
		else cout<<((sama[1][1]==0)?"Yes":"No")<<endl;
		for(int i = 0;i <= n;i++) vec[i].clear();
		k = 0;		
	}
}

int main(){
	desperate_optimization(10);
	int ntc = 1;
	//cin>>ntc;
	for(int tc = 1;tc <= ntc;tc++) hora(tc);
	return 0;
}


