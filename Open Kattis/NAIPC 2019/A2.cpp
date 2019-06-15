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

struct point{
    double x,y;
};

vector<point> vec;
vector<int> order;

double shoelace(point A,point B) {
    return A.x * B.y - A.y * B.x;
}

void hora(int tc) {
    srand(time(NULL));
    int n,k;
    cin>>n>>k;
    for(int i = 0;i < n;i++) {
        point x;
        cin>>x.x>>x.y;
        vec.PB(x);
        order.PB(i);
    }
    const double TIMELIMIT = 2.0;
    srand(time(NULL));
    clock_t t,f;
    t = clock();
    //input
    f = clock() - t;
    int coba = 0;
    double total = 0;
    while(((float)f) < (TIMELIMIT - 0.1) * CLOCKS_PER_SEC) {
        //process
        random_shuffle(order.begin(),order.end());
        vector<int> ambil;
        for(int i = 0;i < k;i++) ambil.PB(order[i]);
        sort(ambil.begin(),ambil.end());
        double res = 0;
        for(int i = 0;i < k;i++) res += shoelace(vec[ambil[i]], vec[ambil[(i + 1) % k]]);
        total += fabs(res) / 2.0;
        coba++;
        f = clock() - t;
    }
    cout<<total / (1.0 * coba)<<endl;
}

int main(){
    desperate_optimization(10);
    int ntc = 1;
    //cin>>ntc;
    for(int tc = 1;tc <= ntc;tc++) hora(tc);
    return 0;
}

