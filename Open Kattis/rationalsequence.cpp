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

int main(){
    //desperate_optimization(10);
    clock_t CLOCK;
    CLOCK = clock();
    
    int ntc;
    cin>>ntc;
    while(ntc--) {
        LL k;
        LL A,B;
        char tmp;
        cin>>k>>A>>tmp>>B;
        LL d = __gcd(A,B);
        A /= d;
        B /= d;
        if(A == 0 || B == 0) assert(0);
        if(A == 1 && B == 1) {
            cout<<k<<" "<<1<<"/"<<2<<endl;
            continue;
        }
        if(B == 1 && A != 1) {
            cout<<k<<" "<<1<<"/"<<(A + 1)<<endl;
            continue;
        }
        LL p,q;
        if(A < B) {
            A = A;
            B = B - A;
            p = A + B;
            q = B;
        }
        else {
            LL naik = A / B;
            A = A - B * naik;
            B = B - A;
            p = A + B;
            q = B;
            q += p * naik;
        }
        cout<<k<<" "<<p<<"/"<<q<<endl;
    }
    cerr<<"PROCESSED TIME "<<(clock() - CLOCK) * 1.0 / (1.0 * CLOCKS_PER_SEC)<<endl;
    return 0;
}


