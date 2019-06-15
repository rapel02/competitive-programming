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

const int N = 500000;

ll arr[N + 5];

int main(){
    desperate_optimization(10);
    ll n,b;
    while(cin>>n>>b) { 
        if(n == -1) break;
        for(int i = 0;i < n;i ++)cin>>arr[i];
        ll lo = 0;
        ll hi = 5000000;
        ll ans = -1;
        while(lo <= hi) {
            ll mid = (lo + hi) / 2;
            ll tot = 0;
            for(int i = 0;i < n;i++) {
                ll many = arr[i] / mid;
                if(arr[i] % mid != 0) many++;
                tot += many; 
            }
            if(tot > b) lo = mid + 1;
            else {
                ans = mid;
                hi = mid - 1;
            }
        }
        cout<<ans<<endl;
    }
}