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
	//desperate_optimization(10);
	int n,m;
	int tc = 0;
	while(cin>>n>>m) {
		getchar();
		if(n + m == 0) break;
		if(tc != 0) cout<<endl;
		tc++;
		ms.clear();
		for(int i = 0;i < n;i++) {
			string s;
			getline(cin,s);
			ms[s] = 1;
		}
		string answ = "";
		double lo = -1;
		double pr = 0;
		while(m--) {
			string nm;
			getline(cin,nm);
			double p;
			LL k;
			cin>>p>>k;
			getchar();
			LL tot = 0;
			for(int i = 0 ;i < k;i++) {
				string s;
				getline(cin,s);
				tot += ms[s];
			}
			if(k > lo * n) {
				lo = k;
				lo /= 1.0 * n;
				pr = p;
				answ = nm;
			}
			else if(1.0 * k / n == lo) {
				if(pr > p) {
					pr = p;
					answ = nm;
				}
			}
		}
		cout<<"RFP #"<<tc<<"\n"<<answ<<endl;
	}
	return 0;
}

