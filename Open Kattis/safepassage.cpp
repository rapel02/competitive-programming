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

ll dist[2][35000];
int arr[16];

int main(){
	desperate_optimization(10);
	int n;
	cin>>n;
	for(int i=0;i<n;i++) cin>>arr[i];
	int pos_now = (1<<n) - 1;
	for(int i=0;i<2;i++) for(int j=0;j<=pos_now;j++) dist[i][j] = 1e18;
	dist[0][pos_now] = 0;
	priority_queue<pair<ll,pair<int,int> > >pq;
	pq.push(MP(0,MP(0,pos_now)));
	while(!pq.empty()){
		ll cost = -pq.top().FI;
		int state = pq.top().SE.FI;
		int bitmask = pq.top().SE.SE;
		int nextbitmask = pos_now - bitmask;
		pq.pop();
		if(state == 0){
			for(int i=0;i<n;i++){
				if(((1<<i) & bitmask) == 0) continue;
				for(int j=i+1;j<n;j++){
					if(((1<<j) & bitmask) == 0) continue;
					int nbitmask = nextbitmask + (1<<i) + (1<<j);
					ll added = max(arr[i],arr[j]);
					if(dist[1][nbitmask] > dist[0][bitmask] + added){
						dist[1][nbitmask] = dist[0][bitmask] + added;
						pq.push(MP(-dist[1][nbitmask],MP(1,nbitmask)));
					}
				}
			}
		}
		else{
			for(int j=0;j<n;j++){
				if(((1<<j) & bitmask) == 0) continue;
				int nbitmask = nextbitmask + (1<<j);
				ll added = arr[j];
				if(dist[0][nbitmask] > dist[1][bitmask] + added){
					dist[0][nbitmask] = dist[1][bitmask] + added;
					pq.push(MP(-dist[0][nbitmask],MP(0,nbitmask)));
				}
			}
		}
	}
	cout<<dist[1][pos_now]<<endl;
	return 0;
}

