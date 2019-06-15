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

ll arr[150000];

int main(){
	desperate_optimization(10);
	ll m,n;
	cin>>m>>n;
	for(int i=0;i<n;i++) cin>>arr[i];
	ll lo = 0;
	ll hi = 2e9;
	ll ans = -1;
	while(lo <= hi){
		ll mid = (lo + hi)/2;
		ll tot = 0;
		for(int i=0;i<n;i++){
			tot += max(0LL,arr[i] - mid);
		}
		if(tot > m) lo = mid + 1;
		else{
			ans = mid;
			hi = mid - 1;
		}
	}
	priority_queue<ull> pq;
	for(int i=0;i<n;i++){
		if(arr[i] > ans){
			m -= (arr[i] - ans);
			arr[i] = ans;
		}
		pq.push(arr[i]);
	}
	while(m != 0){
		ull top = pq.top();
		pq.pop();
		m--;
		pq.push(top - 1);
	}
	ull res = 0;
	while(!pq.empty()){
		res += pq.top() * pq.top();
		pq.pop();
	}
	cout<<res<<endl;
	return 0;
}

