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

int flagged[1000005];
pair<int,int> p[1000005];

int main(){
	desperate_optimization(10);
	ll ans = 0;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		ll x;
		cin>>x;
		p[i].FI = x, p[i].SE = i;
	}
	sort(p,p+n);
	for(int i=0;i<n;i++){
		int pos = p[i].SE;
		if(pos != 0 && flagged[pos - 1] == 1) ans += p[i].FI;
		if(pos != n-1 && flagged[pos + 1] == 1) ans += p[i].FI;
		flagged[pos] = 1;
	}
	cout<<ans<<endl;
	return 0;
}

