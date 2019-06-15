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

double dp[380][3];

int main(){
	desperate_optimization(2);
	int n;
	while(cin>>n){
		if(n == 0) break;
		dp[0][0] = 100000;
		dp[0][1] = 0;
		for(int i=1;i<=n;i++){
			double x;
			cin>>x;
			dp[i][0] = max(dp[i-1][0],floor(dp[i-1][1] * x * 0.97));
			dp[i][1] = max(dp[i-1][1],floor(dp[i-1][0] / x * 0.97));
		}
		cout<<dp[n][0]/100.0<<endl;
	}
	return 0;
}

