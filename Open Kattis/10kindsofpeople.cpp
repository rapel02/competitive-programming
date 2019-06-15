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

string field[10005];
int sets[1005][1005];
int r,c;

int py[] = {0,1,0,-1};
int px[] = {1,0,-1,0};

int main(){
	desperate_optimization(10);
	cin>>r>>c;
	if(r > 1000 || c > 1000) assert(0);
	for(int i=0;i<r;i++) cin>>field[i];
	int k = 0;
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			if(sets[i][j] == 0){
				k++;
				stack<pair<int,int> > stk;
				sets[i][j] = k;
				stk.push(MP(i,j));
				while(!stk.empty()){
					int yy = stk.top().FI;
					int xx = stk.top().SE;
					stk.pop();
					for(int l=0;l<4;l++){
						int yyy = yy + py[l];
						int xxx = xx + px[l];
						if(yyy < 0 || xxx < 0 || yyy >= r || xxx >= c) continue;
						if(sets[yyy][xxx] != 0) continue;
						if(field[yyy][xxx] != field[i][j]) continue;
						sets[yyy][xxx] = k;
						stk.push(MP(yyy,xxx));
					}
				}
			}
		//	cout<<sets[i][j]<<" ";
		}
//		cout<<endl;
	}
	int q;
	cin>>q;
	while(q--){
		int x1,y1,x2,y2;
		cin>>y1>>x1>>y2>>x2;
		x1--,y1--,x2--,y2--;
		if(sets[y1][x1] == sets[y2][x2]){
			if(field[y1][x1] == '0') cout<<"binary"<<endl;
			else cout<<"decimal"<<endl;
		}
		else cout<<"neither"<<endl;
	}
	return 0;
}

