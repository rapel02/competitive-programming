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

bool distone(int r1,int c1,int r2,int c2) {
	if(r1 == r2) {
		return abs(c1 - c2) == 1;
	}
	if(c1 == c2) {
		return abs(r1 - r2) == 1;
	}
	return false;
}

bool passes(int r1,int c1,int r2,int c2,int r3,int c3) {
	if(r1 == r2 && r1 == r3) {
		return min(c2,c3) <= c1 && max(c2,c3) >= c1;
	}
	if(c1 == c2 && c1 == c3) {
		return min(r2,r3) <= r1 && max(r2,r3) >= r1;
	}
	return false;
}

int main(){
	desperate_optimization(10);
	int k,q1,q2;
	while(cin>>k>>q1>>q2) {
		int r1 = k / 8;
		int c1 = k % 8;
		int r2 = q1 / 8;
		int c2 = q1 % 8;
		int r3 = q2 / 8;
		int c3 = q2 % 8;
		if(k == q1) {
			cout<<"Illegal state"<<endl;
			continue;
		}
		if((r2 != r3 && c2 != c3) || passes(r1,c1,r2,c2,r3,c3) || k == q2 || q1 == q2) {
			cout<<"Illegal move"<<endl;
			continue;
		}
		if(distone(r1,c1,r3,c3)) {
			cout<<"Move not allowed"<<endl;
			continue;
		}
		if((k == 56 && q2 == 49) || (k == 0 && q2 == 9) || (k == 7 && q2 == 14) || (k == 63 && q2 == 54)) {
			cout<<"Stop"<<endl;
			continue;
		}
		cout<<"Continue"<<endl;
	}
	return 0;
}

