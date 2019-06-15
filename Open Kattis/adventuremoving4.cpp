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

const ll INF = 1e18;

ll dp[105][205];
ll arr[105];
ll cost[105];

int main(){
	desperate_optimization(10);
	for(int i=0;i<105;i++) for(int j=0;j<205;j++) dp[i][j] = INF;
	dp[0][100] = 0;
	arr[0] = 0;
	cost[0] = INF;
	ll temp;
	cin>>temp;
	int k = 1;
	while(cin>>arr[k]>>cost[k]){
		k++;
	}
	arr[k] = temp;
	priority_queue<pair<ll,pair<int,int> > > pq;
	pq.push(MP(0,MP(0,100)));
	while(!pq.empty()){
		ll costnow = -pq.top().FI;
		int posnow = pq.top().SE.FI;
		int sisanow = pq.top().SE.SE;
		pq.pop();
		if(posnow == k) continue;
		
		//move to next
		if(sisanow >= arr[posnow + 1] - arr[posnow]){
			int sisanext = sisanow - (arr[posnow + 1] - arr[posnow]);
			if(sisanext >= 0 && dp[posnow + 1][sisanext] > costnow){
				dp[posnow + 1][sisanext] = costnow;
				pq.push(MP(-dp[posnow + 1][sisanext],MP(posnow + 1,sisanext)));
			}
		}
		//isi 1 aja deh
		
		if(sisanow < 200 && dp[posnow][sisanow + 1] > costnow + cost[posnow]){
			dp[posnow][sisanow + 1] = costnow + cost[posnow];
			pq.push(MP(-dp[posnow][sisanow + 1],MP(posnow,sisanow + 1)));
		}
	}
	ll mini = INF;
	for(int i=100;i<=200;i++) mini = min(mini,dp[k][i]);
	if(mini == INF) cout<<"Impossible"<<endl;
	else cout<<mini<<endl;
	return 0;
}

