#include <stdio.h>
#include <iostream>
#include <sstream>

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

double dp[2005][1005];

double arr[2005];
int n,m;

double calc(int pos,int lifen){
	int lifem = m - (pos - n + lifen);
	if(lifem == 0) return 1;
	if(lifen == 0) return 0;
	if(dp[pos][lifen] > -0.5) return dp[pos][lifen];
	dp[pos][lifen] = arr[pos] * calc(pos + 1,lifen) + (1 - arr[pos]) * (calc(pos + 1,lifen-1));
	return dp[pos][lifen];
}

int main(){
	desperate_optimization(10);
	cin>>n>>m;
	for(int i=0;i<n+m-1;i++) cin>>arr[i];
	for(int i=0;i<=n+m;i++) for(int j=0;j<=n;j++) dp[i][j] = -1;
	cout<<calc(0,n)<<endl;
	return 0;
}

