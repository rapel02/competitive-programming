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

LL arr[5], D;
LL tp[5], tp2[5];

LL calc2(LL P,LL X) {
    for(int i = 0;i < 3;i++) tp2[i] = tp[i];
    tp2[1] += P;
    tp2[2] += X - P;
    return tp2[0] * tp2[0] + tp2[1] * tp2[1] + tp2[2] * tp2[2] + 7LL * min(tp2[0],min(tp2[1],tp2[2]));
}

LL calc(LL X) {
    LL lo = 0;
    LL hi = D - X;
    for(int i = 0;i < 3;i++) tp[i] = arr[i];
    tp[0] += X;
    while(hi - lo >= 10) {
        LL mid1 = lo + (hi - lo) / 3;
        LL mid2 = hi - (hi - lo) / 3;
        if(calc2(mid1,D - X) > calc2(mid2,D - X)) hi = mid2 - 1;
        else lo = mid1 + 1;
    }
    LL ans = 0;
    for(int i = lo; i <= hi;i++) ans = max(ans,calc2(i,D - X));
    return ans;
}

int main(){
    desperate_optimization(10);
    clock_t CLOCK;
    CLOCK = clock();
    int ntc;
    cin>>ntc;
    while(ntc--){
        cin>>arr[0]>>arr[1]>>arr[2]>>D;
        sort(arr,arr + 3);
        LL lo = 0;
        LL hi = D;
        while(hi - lo >= 10) {
            LL mid1 = lo + (hi - lo) / 3;
            LL mid2 = hi - (hi - lo) / 3;
            if(calc(mid1) > calc(mid2)) hi = mid2 - 1;
            else lo = mid1 + 1;
        }
        LL ans = 0;
        for(int i = lo; i <= hi;i++) {
            ans = max(ans,calc(i));
        }
        cout<<ans<<endl;
    }
    
    cerr<<"PROCESSED TIME "<<(clock() - CLOCK) * 1.0 / (1.0 * CLOCKS_PER_SEC)<<endl;
    return 0;
}


