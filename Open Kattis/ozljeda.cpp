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

const int MAXN = 1e5;

ll arr[MAXN + 5];
ll pref[MAXN + 5];

int main(){
	desperate_optimization(10);
	int n;
	cin>>n;
	ll res = 0;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		res ^= arr[i];
		pref[i] = res;
	}
	arr[n] = res;
	pref[n] = 0;
	n++;
	int q;
	cin>>q;
	while(q--){
		ll l,r;
		cin>>l>>r;
		l--,r--;
		ll lo = 0;
		ll hi = 0;
		if(l % n != 0) lo = pref[l%n-1];
		hi = (pref[n-1] ^ pref[r % n]);
		cout<<(hi ^ lo)<<endl;
	}
	return 0;
}

