#include <stdio.h>
#include <iostream>
#include <sstream>

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

vector<int> vec[3000];
map<ll,int> ms;
ll rms[12000];
int vis[3000];
int par[12000],rpar[12000];
int k = 0;
pair<ll,ll> p[3000];

int augment(int idx){
	if(vis[idx] == 1) return 0;
	vis[idx] = 1;
	for(int i=0;i<vec[idx].size();i++){
		int nx = vec[idx][i];
		if(par[nx] == -1 || augment(par[nx]) == 1){
			par[nx] = idx;
			rpar[idx] = nx;
			return 1;
		}
	}
	return 0;
}

int n;

int MCBM(){
	int ans = 0;
	for(int i=0;i<10000;i++) par[i] = -1;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++) vis[j] = 0;
		ans += augment(i);
	}
	return ans;
}

int main(){
	desperate_optimization(10);
	cin>>n;
	k = 1;
	for(int i=0;i<n;i++){
		cin>>p[i].FI>>p[i].SE;
		if(ms[p[i].FI + p[i].SE] == 0){
			rms[k] = p[i].FI + p[i].SE;
			ms[p[i].FI + p[i].SE] = k++;
		}
		vec[i].PB(ms[p[i].FI + p[i].SE]);
		if(ms[p[i].FI - p[i].SE] == 0){
			rms[k] = p[i].FI - p[i].SE;
			ms[p[i].FI - p[i].SE] = k++;
		}
		vec[i].PB(ms[p[i].FI - p[i].SE]);
		if(ms[p[i].FI * p[i].SE] == 0){
			rms[k] = p[i].FI * p[i].SE;
			ms[p[i].FI * p[i].SE] = k++;
		}
		vec[i].PB(ms[p[i].FI * p[i].SE]);
	}
	int ans = MCBM();
	if(ans != n) cout<<"impossible"<<endl;
	else{
		for(int i=0;i<n;i++){
			ll res = rms[rpar[i]];
			cout<<p[i].FI<<" ";
			if(p[i].FI + p[i].SE == res) cout<<"+ ";
			else if(p[i].FI - p[i].SE == res) cout<<"- ";
			else cout<<"* ";
			cout<<p[i].SE<<" = "<<res<<endl;
		}
	}
	return 0;
}

