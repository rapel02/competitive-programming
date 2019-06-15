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

int ctr[150];

void hex(int x) {
	stack<char> s;
	while(x) {
		int ss = x % 16;
		x/=16;
		if(ss < 10) s.push(ss + '0');
		else s.push(ss - 10 + 'A');
	}
	while(s.size() != 2) s.push('0');
	while(!s.empty()) {
		cout<<s.top();
		s.pop();
	}
}

int main(){
	desperate_optimization(10);
	int ntc;
	cin>>ntc;
	for(int tc=1;tc<=ntc;tc++) {
		string t;
		cin>>t;
		memset(ctr,0,sizeof(ctr));
		int ptr = 0;
		for(int i = 0;i < t.size();i++) {
			char x = t[i];
			if(x == '>') ptr = (ptr + 1) % 100;
			else if(x == '<') ptr = (ptr + 99) % 100;
			else if(x == '+') ctr[ptr] = (ctr[ptr] + 1) % 256;
			else if(x == '-') ctr[ptr] = (ctr[ptr] + 255) % 256;
		}
		cout<<"Case "<<tc<<":";
		for(int i = 0;i < 100;i++) {
			cout<<" ";
			hex(ctr[i]);
		}
		cout<<endl;
	}
	return 0;
}

/*
..++<><<+++>>++++++++++++++++++++++++++>>>+++<+...++<><<+++>>++++++++++++++++++++++++++>>>+++<+...++<><<+++>>++++++++++++++++++++++++++>>>+++<+.
*/

