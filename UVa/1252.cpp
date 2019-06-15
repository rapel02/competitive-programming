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

int val[250];
int dp[1<<12][1<<12];
int r,c;

int calc(int question, int asked) {
	int &res = dp[question][asked];
	if(res != -1) return res;
	res = 1e9;
	int ctr = 0;
	for(int i = 0;i < r;i++) if((question & val[i]) == asked) ctr++;
	if(ctr <= 1) return dp[question][asked] = 0;
	for(int j = 0;j < c;j++) {
		if(question & (1<<j)) continue;
		res = min(res,1 + max(calc(question | (1<<j),asked), calc(question | (1<<j),asked | (1<<j))));
	}
	return res;
}

void hora(int tc) {
	while(cin>>c>>r) {
		if(r + c == 0) break;
		for(int i = 0;i < r;i++) {
			string in;
			val[i] = 0;
			cin>>in;
			for(int j = 0;j < in.size();j++) val[i] = val[i] * 2 + in[j] - '0';
		}
		memset(dp,-1,sizeof dp);
		cout<<calc(0,0)<<endl;
	}
}

int main(){
	desperate_optimization(10);
	int ntc = 1;
	//cin>>ntc;
	for(int tc = 1;tc <= ntc;tc++) hora(tc);
	return 0;
}


