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

map<string,int> ms;

int main(){
	desperate_optimization(10);
	int n,m;
	while(cin>>n) {
		if(n == 0) break;
		cin>>m;
		ms.clear();
		while(n--) {
			string s;
			cin>>s;
			ms[s] = 1;
		}
		int ada = 0;
		while(m--) {
			int k,l;
			cin>>k>>l;
			int tot = 0;
			while(k--) {
				string s;
				cin>>s;
				tot += ms[s];
			}
			if(tot < l) ada = 1;
		}
		cout<<((ada == 0)?"yes":"no")<<endl;
	}
	return 0;
}

