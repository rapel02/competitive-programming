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

typedef long long ll;
typedef unsigned long long ull;

void desperate_optimization(int precision){
    ios_base::sync_with_stdio(false);
  	cin.tie(0);
  	cout.tie(0);
  	cout.setf(ios::fixed);
  	cout.setf(ios::showpoint);
  	cout.precision(precision);
}

vector<pair<int,int> > vec,vec2;

bool cmp(pair<int,int> A,pair<int,int> B){
    return A.FI + A.SE < B.FI + B.SE;
}

bool cmp2(pair<int,int> A,pair<int,int> B){
    return (ll)A.FI * B.SE > (ll)A.SE * B.FI;
}

void pre(){
	for(int i=1;i<=1500;i++){
	    for(int j=1;j<=1500;j++){
	        if(__gcd(i,j) == 1) vec.PB(MP(i,j));
        }
    }
    sort(vec.begin(),vec.end(),cmp);
    for(int i=0;i<100000;i++){
        vec2.PB(vec[i]);
    }
    sort(vec2.begin(),vec2.end(),cmp2);
}

int main(){
	desperate_optimization(10);
    pre();
    int n;
    cin>>n;
    int px = 2e7;
    int py = 0;
    int ambil = n/4;
    if(n%4 != 0) ambil++;
    cout<<px<<" "<<py<<endl;
    n--;
    while(1){
        for(int i=0;i<ambil;i++){
            px += vec2[i].FI;
            py += vec2[i].SE;
            cout<<px<<" "<<py<<endl;
            n--;
            if(n == 0) break;
        }
        if(n == 0) break;
        for(int i=ambil-1;i>=0;i--){
            px -= vec2[i].FI;
            py += vec2[i].SE;
            cout<<px<<" "<<py<<endl;
            n--;
            if(n == 0) break;
        }
        if(n == 0) break;
        for(int i=0;i<ambil;i++){
            px -= vec2[i].FI;
            py -= vec2[i].SE;
            cout<<px<<" "<<py<<endl;
            n--;
            if(n == 0) break;
        }
        if(n == 0) break;
        for(int i=ambil-1;i>=0;i--){
            px += vec2[i].FI;
            py -= vec2[i].SE;
            cout<<px<<" "<<py<<endl;
            n--;
            if(n == 0) break;
        }
        if(n == 0) break;
    }
	return 0;
}

