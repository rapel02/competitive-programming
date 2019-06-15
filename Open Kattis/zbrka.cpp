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
#define endl '\n'
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void desperate_optimization(int precision){
  	ios_base::sync_with_stdio(false);
  	cin.tie(0);
  	cout.tie(0);
  	cout.setf(ios::fixed);
  	cout.setf(ios::showpoint);
  	cout.precision(precision);
}

const ll MOD = 1e9 + 7;
ll dp[1005][10005];
ll pref[10005];

void pre(){
	dp[1][0] = 1;
	pref[0] = 1;
	for(int i=1;i<=10000;i++) pref[i] = pref[i-1];
	for(int i=2;i<=1000;i++){
		for(int j=0;j<=10000;j++){
			int back = j - (i-1);
			if(back > 0) dp[i][j] = (pref[j] - pref[back-1] + MOD)%MOD;
			else dp[i][j] = pref[j];
		}
		for(int j=0;j<=10000;j++){
			if(j == 0) pref[j] = 1;
			else{
				pref[j] = (pref[j-1] + dp[i][j]) % MOD;
			}
		}
	}
}

int main(){
	desperate_optimization(10);
	int n,m;
	cin>>n>>m;
	pre();
	cout<<dp[n][m]<<endl;
	return 0;
}

