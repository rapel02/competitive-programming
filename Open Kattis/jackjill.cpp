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

const int N = 31;
double dist[N][N][N][N];
int py[] = {0,1,0,-1,0};
int px[] = {0,0,1,0,-1};
string arr[N];

pair<int,int> par[N][N][N][N];

string chg = " NESW";

int sx[2],sy[2],fx[2],fy[2];

priority_queue<pair<pair<double,pair<int,int> >,pair<pair<int,int>,pair<int,int> > > > pq;

double sqr(int x) {
    return x * x * 1.0;
}

double calc(int sy,int sx,int fy,int fx) {
    return sqrt(sqr(sy - fy) + sqr(sx - fx) );
}

string res1,res2;

void backtrack(int fy0,int fx0, int fy1,int fx1) {
    if(fy0 == sy[0] && fy1 == sy[1] && fx0 == sx[0] && fx1 == sx[1]) return ;
    pair<int,int> pr = par[fy0][fx0][fy1][fx1];
    int ny0 = fy0 + py[pr.FI];
    int nx0 = fx0 + px[pr.FI];
    int ny1 = fy1 + py[pr.SE];
    int nx1 = fx1 + px[pr.SE];
    backtrack(ny0,nx0,ny1,nx1);
    int ni = pr.FI,nj = pr.SE;
    if(ni > 2) ni = (ni + 3) % 5;
    else if(ni != 0) ni = (ni + 2);
    if(nj > 2) nj = (nj + 3) % 5;
    else if(nj != 0) nj += 2;
    if(chg[pr.FI] != ' ') res1 += chg[ni];
    if(chg[pr.SE] != ' ') res2 += chg[nj];
}

int diff(int y1,int x1,int y0,int x0) {
    return abs(y1 - y0) + abs(x1 - x0);
}

int main(){
    desperate_optimization(2);
    clock_t CLOCK;
    CLOCK = clock();
    int n;
    int isf = 0;
    cout<<"RUNN "<<endl;
    while(cin>>n) {
        if(n == 0) break;
        if(isf == 1) cout<<endl;
        isf = 1;
        for(int i = 0;i < N;i++) for(int j = 0;j < N;j++) for(int k = 0; k < N;k++) for(int l = 0;l < N;l++) dist[i][j][k][l] = -1;
        for(int i = 0;i < n;i++) cin>>arr[i];
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < n;j++) {
                if(arr[i][j] == 'H') sx[0] = j, sy[0] = i;
                if(arr[i][j] == 'h') sx[1] = j, sy[1] = i;
                if(arr[i][j] == 'S') fx[0] = j, fy[0] = i;
                if(arr[i][j] == 's') fx[1] = j, fy[1] = i;
                
            }
        }
        //cout<<"START "<<sy[0]<<" "<<sx[0]<<" "<<sy[1]<<" "<<sx[1]<<endl;
        //cout<<"FINISH "<<fy[0]<<" "<<fx[0]<<" "<<fy[1]<<" "<<fx[1]<<endl;
        while(!pq.empty()) pq.pop();
        dist[sy[0]][sx[0]][sy[1]][sx[1]] = calc(sy[0],sx[0],sy[1],sx[1]);
        int vv = max(diff(sy[0],sx[0],fy[0],fx[0]), diff(sy[1],sx[1],fy[1],fx[1]));
        pq.push(MP(MP(dist[sy[0]][sx[0]][sy[1]][sx[1]],MP(-vv,10000)),MP(MP(sy[0],sx[0]),MP(sy[1],sx[1]))));
        int ctr = 0;
        while(!pq.empty()) {
            double dt= pq.top().FI.FI;
            int dit  =-pq.top().FI.SE.FI;
            int mv   = pq.top().FI.SE.SE;
            int s1sy = pq.top().SE.FI.FI;
            int s1sx = pq.top().SE.FI.SE;
            int s2sy = pq.top().SE.SE.FI;
            int s2sx = pq.top().SE.SE.SE;
            pq.pop();
            //if(dt != dist[s1sy][s1sx][s2sy][s2sx]) continue;
            cout<<"HERE "<<dt<<" "<<dit<<" "<<mv<<" "<<s1sy<<" "<<s1sx<<" "<<s2sy<<" "<<s2sx<<endl;
            for(int i = 0;i < 5;i++) {
                int n1sy = s1sy + py[i];
                int n1sx = s1sx + px[i];
                if(i == 0 && (s1sy != fy[0] || s1sx != fx[0])) continue;
                if(n1sy < 0 || n1sx < 0 || n1sy == n || n1sx == n) continue;
                if(arr[n1sy][n1sx] == '*' || arr[n1sy][n1sx] == 'h' || arr[n1sy][n1sx] == 's') continue;
                for(int j = 0;j < 5;j++) {
                    int n2sy = s2sy + py[j];
                    int n2sx = s2sx + px[j];
                    if(j == 0 && (s2sy != fy[1] || s2sx != fx[1]) ) continue;
                    if(n2sy < 0 || n2sx < 0 || n2sy == n || n2sx == n) continue;
                    if(arr[n2sy][n2sx] == '*' || arr[n2sy][n2sx] == 'H' || arr[n2sy][n2sx] == 'S') continue;
                    double ndt = calc(n1sy,n1sx,n2sy,n2sx);
                    ndt = min(dt,ndt);
                    int rvv = max(diff(n1sy,n1sx,fy[0],fx[0]),diff(n2sy,n2sx,fy[1],fx[1]));
                    if(ndt > dist[n1sy][n1sx][n2sy][n2sx] && mv - 1 >= rvv) {
                        //dist[n1sy][n1sx][n2sy][n2sx] = ndt;
                        dist[s1sy][s1sx][s2sy][s2sx] = dt;
                        pq.push(MP(MP(ndt,MP(mv - 1,-rvv)),MP(MP(n1sy,n1sx),MP(n2sy,n2sx))));
                        //cout<<"NEXT "<<ndt<<" "<<n1sy<<" "<<n1sx<<" "<<n2sy<<" "<<n2sx<<endl;
                        int ni = i,nj = j;
                        if(ni > 2) ni = (ni + 3) % 5;
                        else if(ni != 0) ni = (ni + 2);
                        if(nj > 2) nj = (nj + 3) % 5;
                        else if(nj != 0) nj += 2;
                        par[n1sy][n1sx][n2sy][n2sx] = MP(ni,nj);
                    }
                }
            }
        }
        cout<<dist[fy[0]][fx[0]][fy[1]][fx[1]]<<endl;
        res1 = "",res2 = "";
        backtrack(fy[0],fx[0],fy[1],fx[1]);
        cout<<res1<<endl<<res2<<endl;
    }
    
    cerr<<"PROCESSED TIME "<<(clock() - CLOCK) * 1.0 / (1.0 * CLOCKS_PER_SEC)<<endl;
    return 0;
}


