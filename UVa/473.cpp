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

map<pair<int,vector<int> >,int> dp;
map<pair<int,vector<int> >,int> vis;

int n,t,m;
vector<int> cap;

int solve(int pos,vector<int> tot) {
	if(pos == n) return 0;
	if(vis[MP(pos,tot)] == 1) return dp[MP(pos,tot)];
	vis[MP(pos,tot)] = 1;
	int &res = dp[MP(pos,tot)];
	bool ada = false;
	for(int i = 0;i < m;i++) {
		if(tot[i] + cap[pos] > t) continue;
		tot[i] += cap[pos];
		ada = true;
		res = max(res,solve(pos + 1,tot) + 1);
		tot[i] -= cap[pos];
	}
	if(ada == false) res = max(res,solve(pos + 1,tot));
	return res;
}

void hora(int tc) {
	if(tc != 1) cout<<endl;
	cin>>n>>t>>m;
	cin.ignore();
	vector<int> tmp;
	for(int i = 0;i < m;i++) tmp.PB(0);
	dp.clear(), vis.clear(); cap.clear();
	string in;
	getline(cin,in);
	in += '#';
	for(int i = 0;i < in.size();i++) {
		if(isdigit(in[i])) {
			int num = 0;
			while(isdigit(in[i])) {
				num = num * 10 + in[i] - '0';
				i++;
			}
			cap.PB(num);
		}
	}
	cout<<solve(0,tmp)<<endl;
}

int main(){
	desperate_optimization(10);
	int ntc = 1;
	cin>>ntc;
	for(int tc = 1;tc <= ntc;tc++) hora(tc);
	return 0;
}


