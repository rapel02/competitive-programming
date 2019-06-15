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

map<int,int> ctr;
map<double,LL> DP1, DP2;
int val[1500];
int base[1500];
double weight[1500];
int flag[1500];

const LL MOD = 1e9 + 7;

LL fast(LL A,LL B) {
    LL ans = 1;
    while(B) {
        if(B & 1) ans *= A;
        A *= A;
        B /= 2;
        A %= MOD;
        ans %= MOD;
    }
    return ans;
}

int main(){
    desperate_optimization(10);
    clock_t CLOCK;
    CLOCK = clock();
    string s;
    cin>>s;
    int num = 0;
    double tot = 0;
    for(int i = 0;i < s.size();i++) {
        if(i % 2 == 0 && i != 0) {
            ctr[num]++;
            tot += log2(num);
            num = 0;
        }
        num = num * 10 + (s[i] - '0');
    }
    ctr[num]++;
    tot += log2(num);
    int k = 0;
    for(map<int,int>::iterator it = ctr.begin();it != ctr.end();it++) {
        int v = it->first;
        int qty = it->second;
        //cout<<v<<" "<<qty<<endl;
        for(int i = 0;(1<<i) <= qty; i++) {
            qty -= (1<<i);
            val[k] = (1<<i);
            base[k] = v;
            weight[k] = val[k] * log2(base[k]);
            k++;
        }
        if(qty != 0) {
            val[k] = qty;
            base[k] = v;
            weight[k] = val[k] * log2(base[k]);
            k++;   
        }
    }
    num = 0;
    DP[0] = 1;
    // for(int i = 0;i < k;i++) {
    //     cout<<val[i]<<" "<<base[i]<<" "<<weight[i]<<endl;
    // }
    double mid = tot / 2.0;
    for(int i = 0;i < k;i++) {
        for(map<double,int>::reverse_iterator it = DP.rbegin(); it != DP.rend(); it++) {
            double v = it->first;
            if(v + weight[i] <= mid) {
                DP[v + weight[i]] = 1;
                par[v + weight[i]] = i;
            }
        }
    }
    map<double,int>::reverse_iterator it = DP.rbegin();
    double v = it->first;
    while(v != 0){
        int idx = par[v];
        v -= weight[idx];
        flag[idx] = 1;
    }
    LL v1 = 1, v2 = 1;
    for(int i = 0;i < k;i++) {
        if(flag[i] == 0) v1 = (v1 * fast(base[i],val[i])) % MOD;
        else v2 = (v2 * fast(base[i],val[i])) % MOD;
    }
    cout<<(v1 + v2) % MOD<<endl;
    cerr<<"PROCESSED TIME "<<(clock() - CLOCK) * 1.0 / (1.0 * CLOCKS_PER_SEC)<<endl;
    return 0;
}


