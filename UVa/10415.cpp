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

map<char,pair<string,string> > ms;

int ctr[15],state[15];

int main(){
	desperate_optimization(10);
    ms['c'] = MP("001110","001111");
    ms['d'] = MP("001110","001110");
    ms['e'] = MP("001110","001100");
    ms['f'] = MP("001110","001000");
    ms['g'] = MP("001110","000000");
    ms['a'] = MP("001100","000000");
    ms['b'] = MP("001000","000000");
    ms['C'] = MP("000100","000000");
    ms['D'] = MP("011110","001110");
    ms['E'] = MP("011110","001100");
    ms['F'] = MP("011110","001000");
    ms['G'] = MP("011110","000000");
    ms['A'] = MP("011100","000000");
    ms['B'] = MP("011000","000000");
	int ntc;
	cin>>ntc;
	cin.ignore();
	while(ntc--) {
		memset(ctr,0,sizeof(ctr));
		memset(state,0,sizeof(state));
		string s;
		getline(cin,s);
		for(int i = 0;i < s.size();i++) {
			char x = s[i];
			string st1 = ms[x].FI;
			string st2 = ms[x].SE;
			for(int j = 0;j < 6;j++) {
				if(st1[j] == '0') state[j] = 0;
				else {
					if(state[j] == 0) ctr[j]++;
					state[j] = 1;
				}
			}
			for(int j = 0;j < 6;j++) {
				if(st2[j] == '0') state[j + 5] = 0;
				else {
					if(state[j + 5] == 0) ctr[j + 5]++;
					state[j + 5] = 1;
				}
			}
		}
		for(int i = 1;i <= 10;i++) {
			if(i != 1) cout<<" ";
			cout<<ctr[i];
		}
		cout<<endl;
	}
	return 0;
}

