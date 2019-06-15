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

const int MAXN = 4e6;

int num[MAXN + 5];
vector<int> primes;

void pre(int n){
	num[1] = 1;
	for(ll i=2;i<=min(MAXN,n);i++){
		if(num[i] == 0){
			primes.PB(i);
			for(ll j=i*i;j<=min(MAXN,n);j+=i) num[j] = i;
		}
	}
	if(n <= MAXN) return ;
	for(int i = MAXN + 1;i<=n;i+=MAXN){
		for(int j=0;j<MAXN;j++) num[j] = 0;
		ll lo = i;
		ll hi = min(i + MAXN - 1,n);
		for(int j=0;j<primes.size() && primes[j] * primes[j] <= hi;j++){
			ll nprimes = primes[j];
			ll start = (lo + nprimes - 1) / nprimes * nprimes;
			for(ll k = start;k <= hi;k+=nprimes){
				num[k - lo] = 1;
			}
		}
		for(ll k=lo;k<=hi;k++){
			if(num[k - lo] == 0) primes.PB(k);
		}
	}
}

int main(){
	desperate_optimization(10);
	int n,q;
	cin>>n>>q;
	pre(n);
	cout<<primes.size()<<endl;
	while(q--){
		int x;
		cin>>x;
		int lo = 0;
		int hi = primes.size() - 1;
		int idx = -1;
		while(lo <= hi){
			int mid = (lo + hi)/2;
			if(primes[mid] > x) hi = mid-1;
			else if (primes[mid] < x) lo = mid + 1;
			else{
				idx = mid;
				break;
			}
		}
		if(idx == -1) cout<<0<<endl;
		else cout<<1<<endl; 
	}
	return 0;
}

