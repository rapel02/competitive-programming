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

int mark[1000005];

int main(){
    desperate_optimization(10);
    clock_t CLOCK;
    CLOCK = clock();
    int n;
    cin>>n;
    int ans = 0;
    for(int i = 0;i < n;i++) {
        int x;
        cin>>x;
        if(mark[x] == 0) ans++, mark[x] = 1;
        mark[x]--;
        mark[x-1]++;
    }
    cout<<ans<<endl;
    cerr<<"PROCESSED TIME "<<(clock() - CLOCK) * 1.0 / (1.0 * CLOCKS_PER_SEC)<<endl;
    return 0;
}

