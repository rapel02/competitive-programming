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

int tot[30];
queue<int> q,ans;

int main(){
	//desperate_optimization(10);
	int n,k;
	while(cin>>n>>k) {
		if(n + k == 0) break;
		memset(tot,0,sizeof(tot));
		for(int i = 1;i <= n;i++) q.push(i);
		int ctr = 0;
		int mun = 0;
		while(!q.empty()) {
			int pos = q.front();
			q.pop();
			if(mun == 0) {
				ctr++;
				if(ctr > k) ctr = 1;
				mun += ctr;
				
			}
			int pick = min(mun, 40 - tot[pos]);
			mun -= pick;
			tot[pos] += pick;
			if(tot[pos] >= 40) ans.push(pos);
			else q.push(pos);
		}
		while(!ans.empty()) {
			printf("%3d",ans.front());
			ans.pop();
		}
		cout<<endl;
	}
	return 0;
}

