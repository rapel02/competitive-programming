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

bool palin(int x,int y) {
	string res = "";
	if(x != 0 && x < 10) res += (x + '0');
	else if(x >= 10){
		res += (x / 10 + '0') ;
		res += (x % 10 + '0');
	}
	if(res == "") {
		if(y < 10) res += (y + '0');
		else 
		{
			res += (y / 10 + '0') ;
			res += (y % 10 + '0');
		}
	}
	else {
		res += (y / 10 + '0') ;
		res += (y % 10 + '0');
	}
	for(int i = 0;i < res.size();i++) {
		if(res[i] != res[res.size() - 1 - i]) return false;
	}
	return true;
}

vector<int>xx,yy;

int main(){
	desperate_optimization(10);
	int tc;
	cin>>tc;
	while(tc--) {
		int x,y;
		char t;
		cin>>x>>t>>y;
		y++;
		if(y >= 60) y = 0, x++;
		if(x == 24) x = 0;
		while(!palin(x,y)) {
			y++;
			if(y >= 60) y = 0, x++;
			if(x == 24) x = 0;
		}
		xx.PB(x);
		yy.PB(y);
	}
	//cout<<"ANSWER"<<endl;
	for(int i = 0;i < xx.size();i++) {
		int x = xx[i];
		int y = yy[i];
		if(x < 10) cout<<0;
		cout<<x;
		cout<<":";
		if(y < 10) cout<<0;
		cout<<y<<endl;
	}
	return 0;
}

