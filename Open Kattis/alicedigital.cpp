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

const int N = 1e5;

pair<int,int> arr[N + 5];
int par[N + 5];
int tot[N + 5];
int sudah[N + 5];

bool cmp(pair<int,int> A,pair<int,int> B) {
    if(A.FI != B.FI) return A.FI > B.FI;
    return A.SE < B.SE;
}

int find(int x){
    if(x == par[x]) return x;
    return par[x] = find(par[x]);
}

int main(){
    desperate_optimization(10);
    clock_t CLOCK;
    CLOCK = clock();
    int ntc;
    cin>>ntc;
    while(ntc--) {
        int n,m;
        cin>>n>>m;
        for(int i = 1;i <=n;i++){
            cin>>arr[i].FI;
            arr[i].SE = i;
            tot[i] = arr[i].FI;
            par[i] = i;
            sudah[i] = 0;
        }
        sort(arr + 1, arr + n + 1, cmp);
        int maxi = 0;
        for(int i = 1;i <= n;i++) {
            int val = arr[i].FI;
            int idx = arr[i].SE;
            if(val < m) break;
            if(val != m) {
                if(idx != 1) {
                    if(sudah[idx-1] == 1) {
                        tot[idx] += tot[find(idx-1)];
                        par[find(idx - 1)] = idx;
                    }
                }
                if(idx != n) {
                    if(sudah[idx+1] == 1) {
                        tot[idx] += tot[find(idx+1)];
                        par[find(idx + 1)] = idx;
                    }
                }
                sudah[idx] = 1;
            }
            else {
                int res = 0;
                if(idx != 1 && sudah[idx - 1] == 1) res += tot[find(idx - 1)];
                if(idx != n && sudah[idx + 1] == 1) res += tot[find(idx + 1)];
                res += val;
                maxi = max(maxi,res);
            }
        }
        cout<<maxi<<endl;
    }
    
    cerr<<"PROCESSED TIME "<<(clock() - CLOCK) * 1.0 / (1.0 * CLOCKS_PER_SEC)<<endl;
    return 0;
}


