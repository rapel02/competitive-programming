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

int n,m;

const int N = 200;
int dp[N + 5][N + 5];
int in[N + 5], out[N + 5];
int mapping[N + 5];
int subtree[N + 5];
int cost[N + 5];
int par[N + 5];
map<string,int> ms;
int k;
vector<int> vec[N + 5];

int find(int x) {
	if(x == par[x]) return x;
	return find(par[x]);
}

void dfs(int idx) {
	in[idx] = ++k;
	mapping[k] = idx;
	subtree[idx] = 1;
	for(int i = 0;i < vec[idx].size();i++) {
		int nx = vec[idx][i];
		if(subtree[nx] != 0) continue;
		dfs(nx);
		subtree[idx] += subtree[nx];
	}
	out[idx] = k;
}

int solve(int idx,int tot) {
	if(tot >= m) return 0;
	if(idx > n) return 1e9;
	int &ans = dp[idx][tot];
	if(ans != -1) return ans;
	ans = 1e9;
	ans = min(ans,solve(idx + 1,tot));
	ans = min(ans,solve(out[mapping[idx]] + 1,tot + subtree[mapping[idx]]) + cost[mapping[idx]]);
	return ans;
}

void hora(int tc) {
	string str;
	while(getline(cin,str)){
		if(str == "#") break;
		stringstream ss(str);
		ss>>n>>m;
		k = 0, ms.clear();
		for(int i = 0;i <= n;i++) {
			vec[i].clear();
			par[i] = i;
			subtree[i] = 0;
		}
		memset(dp,-1,sizeof dp);
		for(int i = 1;i <= n;i++) {
			getline(cin,str);
			stringstream ss(str);
			ss>>str;
			if(ms[str] == 0) ms[str] = ++k;
			int head = ms[str];
			ss>>cost[head];
			while(ss>>str){
				if(ms[str] == 0) ms[str] = ++k;
				int tar = ms[str];
				vec[head].PB(tar);
				par[tar] = head;
			}
		}
		k = 0;
		for(int i = 1;i <= n;i++) {
			if(subtree[i] == 0) {
				int head = find(i);
				dfs(head);
			}
		}
		cout<<solve(1,0)<<endl;
	}
	

}

int main(){
	desperate_optimization(10);
	int ntc = 1;
	//cin>>ntc;
	for(int tc = 1;tc <= ntc;tc++) hora(tc);
	return 0;
}


