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

struct point{
	double x,y;
};

vector<point> vec;

double shoelace(point A,point B) {
	return A.x * B.y - A.y * B.x;
}

const int N = 2500;
double pascal[N + 5][N + 5];

void pre() {
	pascal[0][0] = 1;
	for(int i = 1;i <= N;i++) {
		if(i < 10) cout<<i<<": ";
		for(int j = 0;j <= i;j++) {
			if(i == 0 || i == j) pascal[i][j] = pascal[i-1][0] / 2.0;
			else pascal[i][j] = (pascal[i-1][j] + pascal[i-1][j-1]) / 2.0;
			if(i < 10) cout<<pascal[i][j]<<" ";
		}
		if(i < 10) cout<<endl;
	}
}

double pref[N + 5];

void hora(int tc) {
//	pre();
	LL n,k;
	cin>>n>>k;
	for(int i = 0;i < n;i++) {
		point x;
		cin>>x.x>>x.y;
		vec.PB(x);
	}
	double tmp = (1.0 * k * (k - 1)) / (1.0 * (n - k + 1) * (n - k + 2));
	pref[n] = tmp;
	for(int i = n - 1,j = 2;i >= 0;i--,j++) pref[i] = pref[i+1] * (n - k + 4 - j) / (n + 2 - j);
//	for(int i = n;i >= 0;i--) cout<<i<<" "<<pref[i]<<endl;
	double total = 0;
	for(int i = 0;i < n;i++) {
		for(int j = 0;j < n;j++) {
			if(i == j) continue;
			double cross = shoelace(vec[i],vec[j]) / 2.0;
			int selisihdalam = (n + j - i - 1) % n;
//			cout<<"SELISIH DALAM "<<i<<" "<<j<<" "<<selisihdalam<<endl;
			if(selisihdalam >= k - 2) total += cross * pref[selisihdalam];
		}
	}
	total = fabs(total);
	cout<<total<<endl;
}

int main(){
	desperate_optimization(10);
	int ntc = 1;
	//cin>>ntc;
	for(int tc = 1;tc <= ntc;tc++) hora(tc);
	return 0;
}


