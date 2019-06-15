////////////////////////////////////////////
///                                      ///
///         Template ver. 1 rapel        ///
/// Fear is Temporary, Regret is Forever ///
///          Must Try and Get AC         ///
///                                      ///
////////////////////////////////////////////
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
//#include <chrono>
//#include <random>

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
#define PF push_front
#define POB pop_back
#define POF pop_front
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

struct matrix{
    LL arr[55][55];
};

int P[55];
LL n,m;
int sz;

const LL MAXN = 1e5;

inline LL add(LL A,LL B){
    A += B;
    return A % m;
}

inline LL mul(LL A,LL B) {
    LL res = 0;
    while(B) {
        if(B % MAXN) {
            res = add(res,A * (B % MAXN));
        }
        B /= MAXN;
        A = A * MAXN % m;
    }
    return res;
}

matrix mulmat(matrix &A,matrix &B) {
    matrix C;
    for(int i = 0;i <= sz;i++) {
        for(int j = 0;j <= sz;j++) {
            C.arr[i][j] = 0;
            for(int k = 0;k <= sz;k++) {
                C.arr[i][j] = add(C.arr[i][j],mul(A.arr[i][k], B.arr[k][j]));
            }
        }
    }
    return C;
}

void hora(int tc) {
    cin>>n>>m;
    string s;
    cin>>s;
    sz = s.size();
    int i = 0,j = -1;
    P[i] = j;
    while(i < sz) {
        while(j >= 0 && s[i] != s[j]) j = P[j];
        i++, j++;
        P[i] = j;
    }
    matrix base, res;
    for(int i = 0;i <= sz;i++) for(int j = 0;j <= sz;j++) base.arr[i][j] = 0;
    for(int i = 0;i <= sz;i++) for(int j = 0;j <= sz;j++) res.arr[i][j] = ((i == j)?1:0);
    for(int i = 0;i < sz;i++) {
        for(int j = 0;j < 26;j++) {
            int idx = i;
            while(idx >= 0 && s[idx] - 'a' != j) idx = P[idx];
            idx++;
            base.arr[i][idx]++;
        }
    }
    base.arr[sz][sz] = 26;
//  for(int i = 0;i <= sz;i++) {
//      for(int j = 0;j <= sz;j++) cout<<base.arr[i][j]<<" ";
//      cout<<endl;
//  }
    while(n) {
        if(n & 1) res = mulmat(base,res);
        base = mulmat(base,base);
        n /= 2;
    }
    cout<<res.arr[0][sz]<<endl;
}

int main(){
    desperate_optimization(10);
    int ntc = 1;
    cin>>ntc;
    for(int tc = 1;tc <= ntc;tc++) hora(tc);
    return 0;
}

