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

typedef unsigned long long LL;

void desperate_optimization(int precision){
  	ios_base::sync_with_stdio(false);
  	cin.tie(0);
  	cout.tie(0);
  	cout.setf(ios::fixed);
  	cout.setf(ios::showpoint);
  	cout.precision(precision);
}

void hora(int tc) {
	LL p,q,n;
	cin>>p>>q>>n;
	LL red = q / __gcd(p,q);
    LL maxn = n / red * red;
	LL tot = n * (n + 1) / 2 * p;
	LL lattice = n + (n * p) + n - 1;
	LL area = n * p * n;
	LL pts = area - lattice + 2;
	pts /= 2;
	pts += (n * p / q) + n / red;
	if(maxn / red) pts--;
	pts /= q;
	if(q % p == 0) pts++;
//	for(LL i = maxn + 1;i <= n;i++) pts += i * p / q;
	cout<<tot - pts * q<<endl;
}

int main(){
//	desperate_optimization(10);
	int ntc = 1;
	cin>>ntc;
	for(int tc = 1;tc <= ntc;tc++) hora(tc);
	return 0;
}


