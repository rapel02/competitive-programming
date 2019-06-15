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


vector<int> vec[300003];
int col[300003];

ll BIT[2][300003];
int n;
int fin[300003],fout[300003];
int k = 0;

void traverse(int idx){
    fin[idx] = ++k;
    for(int i=0;i<vec[idx].size();i++){
        int nx = vec[idx][i];
        traverse(nx);
    }
    fout[idx] = k;
}

void update(int idx,int pr,ll added){
    for(int x = idx;x <= n; x += (x & (-x))) BIT[pr][x] ^= added;
}

ll query(int idx,int pr){
    ll tot = 0;
    for(int x = idx; x > 0; x -= (x & (-x))) tot ^= BIT[pr][x];
    return tot;
}

int total[105];

int main(){
	desperate_optimization(10);
	int q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
	    cin>>col[i];
	    col[i]--;
    }
	for(int i=2;i<=n;i++){
	    int x;
	    cin>>x;
	    vec[x].PB(i);
    }
    traverse(1);
    for(int i=1;i<=n;i++) update(fin[i],col[i]/50,1LL<<(col[i]%50) );
    while(q--){
        int type,pos;
        cin>>type>>pos;
        if(type == 0){
            int ans = 0;
            for(int i=0;i<2;i++){
                ll re = (query(fout[pos],i) ^ query(fin[pos]-1,i) );
                for(int j=0;j<50;j++){
                    if((re & (1LL<<j))){
                        ans++;
                    }
                }
            }
            cout<<ans<<endl;
        }
        else{
            update(fin[pos],col[pos] / 50,1LL<<(col[pos]%50));
            col[pos] = type;
            col[pos]--;
            total[col[pos]]++;
            update(fin[pos],col[pos] / 50,1LL<<(col[pos]%50));
        }
    }
	return 0;
}

