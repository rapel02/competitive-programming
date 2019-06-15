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

ll fast(ll A,ll B){
    ll ans = 1;
    while(B){
        if(B & 1) ans *= A;
        A *= A;
        B /= 2;
    }
    return ans;
}

int main(){
    desperate_optimization(10);
    ll n;
    while(cin>>n){
        if(n == 0) break;
        int ans = 1;
        for(ll i=2;i<=33;i++){
            for(ll j=1;;j++){
                double loge = i * 1.0 * log10(j);
                if(loge > 10) break;
                else{
                    if(fast(j,i) == n) ans = i;
                    if(fast(-j,i) == n) ans = i;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
