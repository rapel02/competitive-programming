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

int dp[3500];
ll rem[3500];
ll arr[3500];

int main(){
  desperate_optimization(10);
  int n;
  cin>>n;
  for(int i=1;i<=n;i++) cin>>arr[i];
  dp[0] = 0;
  for(int i=1;i<=n;i++){
    ll tot = arr[i];
    for(int j=i-1;j>=0;j--){
      if(rem[j] <= tot){
        dp[i] = max(dp[i],dp[j] + 1);
        break;
      }
      tot += arr[j];
    }
    rem[i] = tot;
  }
  cout<<dp[n]<<endl;
  return 0;
}

