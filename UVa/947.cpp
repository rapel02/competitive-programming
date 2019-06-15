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

string s;
int a,b;
int tot = 0;

void rec(int sisa, string re) {
	if(sisa == 0) {
		int tota = 0;
		int totb = 0;
		int arr[10],arr2[10];
		for(int i = 0;i < 10;i++)arr[i] = arr2[i] = 0;
		for(int i = 0;i < s.size();i++) {
			if(re[i] == s[i]) tota++;
			arr[re[i]-'0']++;
			arr2[s[i]-'0']++;
		}
		for(int i =1;i < 10;i++) totb += min(arr[i],arr2[i]);
		totb -= tota;
		if(a == tota && b == totb) {
			tot++;
		}
		return ;
	}
	for(char x = '1'; x <= '9';x++) {
		rec(sisa - 1,re + x);
	}
}

int main(){
	desperate_optimization(10);
	int ntc;
	cin>>ntc;
	while(ntc--) {
		tot = 0;
		cin>>s>>a>>b;
		rec(s.size(),"");
		cout<<tot<<endl;
	}
	return 0;
}

