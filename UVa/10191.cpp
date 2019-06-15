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

struct times{
	int hh,mm;
	int state;
};

vector<times> vec;

bool cmp(times A,times B){
	if(A.hh * 60 + A.mm != B.hh * 60 + B.mm) return A.hh * 60 + A.mm < B.hh * 60 + B.mm;
	return A.state > B.state;
}

int main(){
	//desperate_optimization(10);
	int cmd;
	int tc = 0;
	while(cin>>cmd) {
		tc++;
		int answ = -1;
		int hh = 0, mm = 0;
		string s1,s2,s3;
		vec.clear();
		while(cmd--) {
			cin>>s1;
			cin.ignore();
			cin>>s2;
			getline(cin,s3);
			int nhh = (s1[0] - '0') * 10 + (s1[1] - '0');
			int nmm = (s1[3] - '0') * 10 + (s1[4] - '0');
			int phh = (s2[0] - '0') * 10 + (s2[1] - '0');
			int pmm = (s2[3] - '0') * 10 + (s2[4] - '0');
			times x;
			x.hh = nhh, x.mm = nmm;
			x.state = 1;
			vec.PB(x);
			x.hh = phh, x.mm = pmm;
			x.state = -1;
			vec.PB(x);
		}
		times x;
		x.hh = 18, x.mm = 0;
		x.state = 1;
		vec.PB(x);
		x.hh = 10, x.mm = 0;
		x.state = -1;
		vec.PB(x);
		x.hh = 10, x.mm = 0;
		x.state = 1;
		vec.PB(x);
		sort(vec.begin(),vec.end(),cmp);
		int tot = 0;
		for(int i = 0; i < vec.size();i++) {
			tot += vec[i].state;
			if(tot == 0) {
				int ph = vec[i].hh * 60 + vec[i].mm;
				int pph = vec[i+1].hh * 60 + vec[i+1].mm;
				if(pph - ph > answ) {
					answ = pph - ph;
					hh = vec[i].hh;
					mm = vec[i].mm;
				}
			}
		}
		printf("Day #%d: the longest nap starts at %02d:%02d and will last for ",tc,hh,mm);
		int h = answ / 60;
		int m = answ % 60;
		if(h != 0) {
			printf("%d hours and ",h);
		}
		printf("%d minutes.\n",m);
	}
	return 0;
}

