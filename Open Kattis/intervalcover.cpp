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

vector<int> ans;

pair<pair<double,double>,int> p[25000];

int main(){
	//desperate_optimization(10);
	double A,B;
	while(cin>>A>>B){
		ans.clear();
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>p[i].FI.FI>>p[i].FI.SE;
			p[i].SE = i;
		}
		sort(p,p+n);
		double r = A;
		int idx = -1;
		double maxi = r;
		for(int i=0;i<n;i++){
			if(p[i].FI.FI > r){
				if(idx == -1 || maxi < r) break;
				ans.PB(idx);
				r = maxi;
				maxi = r; idx = -1;
				if(r >= B) break;
			}
			if(p[i].FI.FI <= r && p[i].FI.SE >= maxi){
				maxi = p[i].FI.SE;
				idx = p[i].SE;
			}
		}
		if(idx != -1){
			ans.PB(idx);
			r = maxi;
		}
		if(ans.size() == 0 || r < B) cout<<"impossible"<<endl;
		else{
			sort(ans.begin(),ans.end());
			cout<<ans.size()<<endl;
			for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
			cout<<endl;
		}
	}
	return 0;
}

