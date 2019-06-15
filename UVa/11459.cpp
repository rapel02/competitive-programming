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

int mapping[150];
int pos[1500000];

int main(){
	desperate_optimization(10);
	int tc;
	cin>>tc;
	while(tc--) {
		int A,B,C;
		cin>>A>>B>>C;
		for(int i = 1;i < 150;i++) mapping[i] = i;
		for(int i = 1;i <= A;i++) pos[i] = 1;
		while(B--) {
			int u,v;
			cin>>u>>v;
			mapping[u] = v;
		}
		int win = 0;
		int player = 1;
		while(C--) {
			int x;
			cin>>x;
			if(win == 1) continue;
			pos[player] = min(100,mapping[pos[player] + x]);
			if(pos[player] == 100) win = 1;
			player++;
			if(player > A) player = 1;
		}
		for(int i = 1;i <= A;i++) {
			cout<<"Position of player "<<i<<" is "<<pos[i]<<".\n" ;
		}
	}
	return 0;
}

