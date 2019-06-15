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

int A[105],B[105];

int check(){
	int a[105],b[105];
	for(int i=0;i<=100;i++) a[i] = A[i],b[i] = B[i];
	int ans = 0;
	int lo = 0;
	int hi = 100;
	while(lo <= 100 || hi >= 0){
		int red = min(a[lo],b[hi]);
		if(red != 0) ans = max(ans,lo + hi);
		a[lo] -= red;
		b[hi] -= red;
		if(a[lo] == 0) lo++;
		if(b[hi] == 0) hi--;
	}
	return ans;
}

int main(){
	desperate_optimization(10);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int x,y;
		cin>>x>>y;
		A[x]++;
		B[y]++;
		cout<<check()<<endl;
	}
	return 0;
}

