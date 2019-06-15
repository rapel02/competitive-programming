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

ll fast(ll A,ll B,ll MOD){
	ll ans = 1;
	while(B){
		if(B & 1) ans *= A;
		A *= A;
		B /= 2;
		A %= MOD;
		ans %= MOD;
	}
	return ans;
}

int main(){
	//desperate_optimization(10);
	ll A,B;
	cin>>A>>B;
	if(A % 2 == 1) cout<<0<<endl;
	else cout<<fast(A/2,B,A)<<endl;
	return 0;
}

