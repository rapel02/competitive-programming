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

const int N = 1e5;
ll counting[2 * N + 6];
ll arr[N + 6];

int main(){
	desperate_optimization(10);
	int n,b;
	cin>>n>>b;
	int idx = -1;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		if(arr[i] == b) idx = i;
	}
	if(idx == -1){
		cout<<0<<endl;
		return 0;
	}
	else{
		ll mval = N + 5;
		ll res = 0;
		for(int i=idx;i>=1;i--){
			if(arr[i] < b) mval--;
			else if(arr[i] > b) mval++;
			counting[mval]++;
		}
		mval = N + 5;
		for(int i=idx;i<=n;i++){
			if(arr[i] < b) mval--;
			else if(arr[i] > b) mval++;
			ll opp = N + 5 + (N + 5 - mval);
			res += counting[opp];
		}
		cout<<res<<endl;
	}
	return 0;
}

