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

int calc(ll A,ll B){
	if(A < B) swap(A,B);
	if(B == 0) return 0;
	ll red = A / B;
	ll ans = 1 - calc(B,A - red * B);
	if(ans == 1) return ans;
	if(red != 1) ans = 1 - calc(B, A - (red - 1) * B);
	return ans;
}

int main(){
	desperate_optimization(10);
	ll A,B;
	while(cin>>A>>B){
		if(A + B == 0) break;
		cout<<((calc(A,B) == 1)?"Stan":"Ollie")<<" wins"<<endl;
	}
	return 0;
}

