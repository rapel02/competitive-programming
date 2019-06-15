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

int check(int x) {
	int tot = 0;
	while(x){
		tot += x / 5;
		x /= 5;
	}
	return tot;
}

void hora(int tc) {
	string s;
	cin>>s;
	int zero = 0;
	while(s.back() == '0') {
		zero++;
		s.pop_back();
	}
	int last = s.back();
	s.pop_back();
	if(s.size() != 0) last = (s.back() - '0') * 10 + last;
	last -= '0';
	int lo = 1;
	int hi = 1e6;
	int res = -1;
	while(lo <= hi) {
		int mid = (lo + hi) / 2;
		if(check(mid) >= zero) {
			res = mid;
			hi = mid - 1;
		}
		else lo = mid + 1;
	}
	int ss = 0;
	int re = 1;
	for(int i = 1; ;i++) {
		int s = i;
		while(s % 5 == 0) s /= 5;
		while(ss < zero && s % 2 == 0) s /= 2, ss++;
		s %= 100;
		re *= s;
		re %= 100;
		if(re == last && i >= res) {
			cout<<i<<endl;
			return ;
		}
	}
}

int main(){
	desperate_optimization(10);
	int ntc = 1;
	//cin>>ntc;
	for(int tc = 1;tc <= ntc;tc++) hora(tc);
	return 0;
}


