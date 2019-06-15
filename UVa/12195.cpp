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

string test = "WHQESTX";
int arr[] = {64,32,16,8,4,2,1};

int main(){
	desperate_optimization(10);
	string in;
	while(cin>>in) {
		if(in == "*") break;
		int ans = 0;
		int tot = 0;
		for(int i = 0;i < in.size();i++) {
			char x = in[i];
			if(x == '/') {
				if(tot == 64) ans++;
				tot = 0;
			}
			else {
				for(int j = 0;j < 7;j++) {
					if(test[j] == x) tot += arr[j];
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

