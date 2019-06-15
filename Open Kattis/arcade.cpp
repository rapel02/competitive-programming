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

const int N = 600;

double arr[N][N];
double rhs[N];
int num[35][35];
int n;

pair<int,int> pos[N];

int py[] = {-1,-1,1,1};
int px[] = {-1,0,0,1};

void print() {
    for(int i = 1;i <= n;i++) {
        for(int j = 1; j <= n;j++) cout<<arr[i][j]<<" ";
        cout<<rhs[i]<<endl;
    }
    cout<<"==============="<<endl;
}

void gaussjordan() {
    for(int i = 1; i <= n;i++) {
//        print();
        double divisible = arr[i][i];
        for(int j = 1; j <= n;j++) arr[i][j] /= divisible;
        rhs[i] /= divisible;
        for(int j = 1; j <= n; j++) {
            if(i == j) continue;
            double mul = -arr[j][i];
            for(int k = 1; k <= n; k++) {
                arr[j][k] = arr[j][k] + mul * arr[i][k];
            }
            rhs[j] = rhs[j] + mul * rhs[i];
        }
//        print();
    }
}

int main(){
    desperate_optimization(10);
    clock_t CLOCK;
    CLOCK = clock();
    int h;
    cin>>h;
    n = h * (h + 1) / 2;
    int idx = 0;
    for(int i = 1;i <= h;i++) {
        for(int j = 1; j <= i;j++) {
            idx++;
            num[i][j] = idx;
            pos[idx] = MP(i,j);
        }
    }
    for(int i = 1;i <= n;i++) cin>>rhs[i];
    for(int i = 1;i <= n;i++) {
        int posy = pos[i].FI;
        int posx = pos[i].SE;
        for(int j = 0;j < 5;j++) {
            double x;
            cin>>x;
            if(j == 4) {
                rhs[i] *= x;
                continue;
            }
            int yy = posy + py[j];
            int xx = posx + px[j];
            if(yy <= 0 || xx <= 0 || xx > yy || yy > h) continue;
            arr[i][num[yy][xx]] = -x;
        }
        arr[i][i] = 1;
    }
    gaussjordan();
    double res = 0;
    cout<<rhs[1]<<endl;
    cerr<<"PROCESSED TIME "<<(clock() - CLOCK) * 1.0 / (1.0 * CLOCKS_PER_SEC)<<endl;
    return 0;
}


