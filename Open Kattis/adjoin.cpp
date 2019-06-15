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

vector<int> data;

vector<int> vec[150000];
int vis[150000];

void desperate_optimization(int precision){
  	ios_base::sync_with_stdio(false);
  	cin.tie(0);
  	cout.tie(0);
  	cout.setf(ios::fixed);
  	cout.setf(ios::showpoint);
  	cout.precision(precision);
}

void traverse(int idx){
	queue<int> q;
	int last = idx;
	vis[idx] = 0;
	q.push(idx);
	while(!q.empty()){
		last = q.front();
		q.pop();
		for(int i=0;i<vec[last].size();i++){
			int nx = vec[last][i];
			if(vis[nx] == 0) continue;
			q.push(nx);
			vis[nx] = 0;
		}
	}
	q.push(last);
	vis[last] = 1;
	while(!q.empty()){
		last = q.front();
		q.pop();
		for(int i=0;i<vec[last].size();i++){
			int nx = vec[last][i];
			if(vis[nx] != 0) continue;
			q.push(nx);
			vis[nx] = vis[last]+1;
		}
	}
	data.push_back(vis[last]);
}

int main(){
	desperate_optimization(10);
	int c,l;
	cin>>c>>l;
	for(int i=0;i<l;i++){
		int x,y;
		cin>>x>>y;
		vec[x].PB(y);
		vec[y].PB(x);
	}
	for(int i=0;i<c;i++) vis[i] = -1;
	for(int i=0;i<c;i++){
		if(vis[i] == -1) traverse(i);
	}
	sort(data.begin(),data.end());
	int r1 = data.back() - 1;
	int res = 0;
	int res2 = 0;
	res += data.back()/2;
	data.pop_back();
	if(!data.empty()){
		res += data.back()/2 + 1,res2 += data.back()/2;
		data.pop_back();
		if(!data.empty()) res2 += data.back()/2 + 2;
	}	
	cout<<max(max(r1,res2),res)<<endl;
	return 0;
}

