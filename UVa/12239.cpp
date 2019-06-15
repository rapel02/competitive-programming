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

int stats[105];
int arr[105];

int main(){
	desperate_optimization(10);
	int n,m;
	while(cin>>n>>m) {
		if(n + m == 0) break;
		for(int i = 0;i < m;i++) cin>>arr[i];
		memset(stats,0,sizeof(stats));
		for(int i = 0;i < m;i++) {
			for(int j = i;j < m;j++) stats[abs(arr[i] - arr[j])] = 1;
		}
		int ctr = 0;
		for(int i = 0;i <= n;i++) ctr += stats[i];
		if(ctr == n + 1) cout<<'Y'<<endl;
		else cout<<"N"<<endl; 
	}
	return 0;
}

