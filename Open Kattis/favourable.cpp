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

string ending[405];
ll dp[405];
vector<int> vec[405];

ll traverse(int idx){
	if(dp[idx] != -1) return dp[idx];
	dp[idx] = 0;
	if(ending[idx] == "favourably") return dp[idx] = 1;
	for(int i=0;i<vec[idx].size();i++){
		int nx = vec[idx][i];
		dp[idx] += traverse(nx);
	}
	return dp[idx];
}

int main(){
	desperate_optimization(10);
	int ntc;
	cin>>ntc;
	while(ntc--){
	    for(int i=0;i<=400;i++){
	        ending[i] = "";
	        dp[i] = -1;
	        vec[i].clear();
        }
	    int n;
	    cin>>n;
        while(n--){
            int x;
            cin>>x;
            string s;
            cin.ignore();
            getline(cin,s);
            if(s[0] >='0' && s[0] <= '9'){
                stringstream ss(s);
                int w;
                while(ss>>w){
                    vec[x].PB(w);
                }
            }
            else ending[x] = s;
        }
        cout<<traverse(1)<<endl;
    }
	return 0;
}

