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

typedef long long ll;
typedef unsigned long long ull;

void desperate_optimization(int precision){
  	ios_base::sync_with_stdio(false);
  	cin.tie(0);
  	cout.tie(0);
  	cout.setf(ios::fixed);
  	cout.setf(ios::showpoint);
  	cout.precision(precision);
}

string in;
string pat = "welcome to code jam";
ll dp[20][505];
int len;


ll calc(int pos,int poschar){
	if(pos == pat.length()) return 1LL;
	if(poschar == len) return 0;
	if(dp[pos][poschar] != -1) return dp[pos][poschar];
	dp[pos][poschar] = 0;
	if(pat[pos] == in[poschar]) dp[pos][poschar] = calc(pos + 1,poschar + 1);
	dp[pos][poschar] += calc(pos,poschar + 1);
	return dp[pos][poschar] %= 10000;
}

int main(){
	desperate_optimization(10);
	int ntc;
	cin>>ntc; cin.get();
	for(int tc=1;tc<=ntc;tc++){
		for(int i=0;i<20;i++) for(int j=0;j<505;j++) dp[i][j] = -1;
		getline(cin,in);
		len = in.length();
		cout<<"Case #"<<tc<<": "<<setw(4)<<setfill('0')<<calc(0,0)<<endl;
	}
	return 0;
}

