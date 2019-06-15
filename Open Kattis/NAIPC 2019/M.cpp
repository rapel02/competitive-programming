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

const int N = 100000;
vector<int> vec[N + 5];
LL lo[N + 5], hi[N + 5];
int inp[N + 5];
const LL MOD = 1e9 + 7;
int M,m,n;

int res[N + 5];
bool mark[N + 5];

void BF(int x) {
	if(x == n + 1) {
		bool err = false;
		for(int i = 0;i < M;i++) {
			int maxi = -1, resw = -1;
			for(int j = 1;j <= n;j++) {
				int c = (res[j] ^ i);
				if(c > maxi) {
					maxi = c, resw = j;
				}
			}
			if(inp[i] != resw) err = true;
		}
		if(err == false) {
			for(int j = 1;j <= n;j++) cout<<res[j]<<" ";
			cout<<endl;
		}
		return ;
	}
	else {
		for(int i = 0;i < M;i++) {
			if(mark[i]) continue;
			mark[i] = 1;
			res[x] = i;
			BF(x + 1);
			mark[i] = 0;
		}
	}
}

void hora(int tc) {
	cin>>m>>n;
	M = (1<<m);
	for(int i = 0;i < M;i++) {
		cout<<i<<": ";
		for(int j = 0;j < M;j++) cout<<(i ^ j)<<" ";
		cout<<endl;
	}
	for(int i = 0;i < M;i++) {
		cin>>inp[i];
		vec[inp[i]].PB(i);
	}
	BF(1);
	bool err = false;
	for(int i = 1;i <= n;i++) {
		lo[i] = hi[i] = vec[i][0];
		for(int j = 1;j < vec[i].size();j++) {
			int nx = vec[i][j];
			if(nx != hi[i] + 1) err = true;
			hi[i]++;
		}
	}
	if(err == true) {
		cout<<0<<endl;
		return ;
	}
	LL res = 1;
	for(int i = 1;i <= n;i++) res = res * (hi[i] - lo[i] + 1) % MOD;
	cout<<res<<endl;
}

int main(){
	//desperate_optimization(10);
	int ntc = 1;
	//cin>>ntc;
	for(int tc = 1;tc <= ntc;tc++) hora(tc);
	return 0;
}


