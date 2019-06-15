#include <stdio.h>
#include <iostream>
#include <sstream>
#include <iomanip>

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

typedef long long LL;
typedef unsigned long long ULL;

void desperate_optimization(int precision){
  	ios_base::sync_with_stdio(false);
  	cin.tie(0);
  	cout.tie(0);
  	cout.setf(ios::fixed);
  	cout.setf(ios::showpoint);
  	cout.precision(precision);
}

int sum[25];
int num[25];

int main(){
	desperate_optimization(10);
	int b,n;
	while(cin>>b>>n) {
		if(b + n == 0) break;
		for(int i = 1; i <= b;i++) {
			cin>>num[i];
			sum[i] = 0;
		}
		while(n--) {
			int x,y,c;
			cin>>x>>y>>c;
			sum[x] -= c;
			sum[y] += c;
		}
		int ada = 0;
		for(int i =1; i <= b;i++) {
			if(-sum[i] > num[i]) ada = 1;
		}
		cout<<((ada==0)?"S":"N")<<endl;
	}
	return 0;
}

