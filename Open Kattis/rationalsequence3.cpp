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

void desperate_optimization(int precision){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(precision);
}

typedef long long ll;
typedef unsigned long long ull;

pair<ll,ll> backtrack(ll n) {
    if(n == 1) return MP(1,1);
    pair<ll,ll> tmp = backtrack(n/2);
    if(n % 2 == 0) return MP(tmp.FI,tmp.FI + tmp.SE);
    return MP(tmp.FI + tmp.SE,tmp.SE);
}

int main(){
    desperate_optimization(10);
    int ntc;
    cin>>ntc;
    for(int tc=1;tc<=ntc;tc++) {
        ll n;
        int k;
        cin>>k>>n;
        pair<ll,ll> p = backtrack(n);
        cout<<k<<" "<<p.FI<<"/"<<p.SE<<endl;
    }
}