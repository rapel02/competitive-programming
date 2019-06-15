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

vector<pair<int,int> > vec;


int main() {
    desperate_optimization(10);
    int n;
    while(cin>>n){
        if(n == 0) break;
        vec.clear();
        int tot = 0;
        for(int i = 0 ;i < n;i++) {
            int x,y;
            cin>>x>>y;
            vec.PB(MP(x,y));
        }
        int maxi = 1;
        for(int i = 0; i < n;i++) {
            map<pair<int,int>,int> ms;
            for(int j = 0;j < n;j++) {
                if(i == j) continue;
                int y = vec[i].SE - vec[j].SE;
                int x = vec[i].FI - vec[j].FI;
                int d = __gcd(x,y);
                if(d == 0) d = 1;
                x /= d, y /= d;
                ms[MP(x,y)]++;
                maxi = max(maxi,ms[MP(x,y)] + 1);
            }
        }
        cout<<maxi<<endl;
    }
}