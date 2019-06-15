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

int num[2005];
int arr[105];
int k = 0;
int n,m;
int dp[105][2005][2];

int calc(int x){
    return 2 * x / 3;
}

int solve(int idx,int st,int breaked) {
    if(idx == n) return 0;
    if(dp[idx][st][breaked] != -1) return dp[idx][st][breaked];
    if(breaked == 0) {
        return dp[idx][st][breaked] = max(min(num[st],arr[idx]) + solve(idx + 1,min(st + 1,k), breaked), solve(idx + 1,max(0,st - 1),1));
    }
    else if(breaked == 1) {
        return dp[idx][st][breaked] = max(min(num[st],arr[idx]) + solve(idx + 1,min(st + 1,k), 0), solve(idx + 1,0,0));
    }
}

int main(){
    desperate_optimization(10);
    clock_t CLOCK;
    CLOCK = clock();
    cin>>n>>m;
    num[0] = m;
    for(int i = 1; ; i++) {
        if(num[i-1] == calc(num[i-1])) break;
        k++;
        num[i] = calc(num[i-1]);
    }
    for(int i = 0; i < n;i++) cin>>arr[i];
    memset(dp,-1,sizeof(dp));
    cout<<solve(0,0,0)<<endl;
    cerr<<"PROCESSED TIME "<<(clock() - CLOCK) * 1.0 / (1.0 * CLOCKS_PER_SEC)<<endl;
    return 0;
}