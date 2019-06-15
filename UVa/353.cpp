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

int tot = 0;
string s;
set<string>st;

int check(int u,int v) {
	for(int i = u;i <= v;i++) {
		if(s[i] != s[v - (i - u)]) return 0;
	}
	string res = "";
	for(int i = u;i <= v;i++) res += s[i];
	st.insert(res);
	return 1;
}



int main(){
	desperate_optimization(10);
	while(cin>>s) {
		tot = 0;
		st.clear();
		for(int i = 0;i < s.length();i++) {
			for(int j = i; j < s.length();j++) {
				tot += check(i,j);
			}
		}
		cout<<"The string '"<<s<<"' contains "<<st.size()<<" palindromes."<<endl;
	}
	return 0;
}

