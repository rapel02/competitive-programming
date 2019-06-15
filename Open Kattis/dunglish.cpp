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

const int N = 20;

string words[N + 5];

map<string,int> mcor, mfalse;
map<string,string> mmap;

int main(){
    desperate_optimization(10);
    clock_t CLOCK;
    CLOCK = clock();
    int n;
    cin>>n;
    for(int i = 0; i < n;i++) cin>>words[i];
    int m;
    cin>>m;
    while(m--){
        string s1,s2,re;
        cin>>s1>>s2>>re;
        mmap[s1] = s2;
        if(re == "correct") mcor[s1]++;
        else mfalse[s1]++;
    }
    LL ways = 1;
    LL benar = 1;
    for(int i = 0;i < n;i++) {
        ways *= (mcor[words[i]] + mfalse[words[i]]);
        benar *= mcor[words[i]];
    }
    LL salah = ways - benar;
    if(ways == 1) {
        for(int i = 0;i < n;i++){
            cout<<mmap[words[i]]<<" ";
        }
        cout<<endl;
        if(benar==0) cout<<"in"; 
        cout<<"correct\n";
    }
    else {
        cout<<benar<<" correct"<<endl;
        cout<<salah<<" incorrect"<<endl;
    }
    cerr<<"PROCESSED TIME "<<(clock() - CLOCK) * 1.0 / (1.0 * CLOCKS_PER_SEC)<<endl;
    return 0;
}


