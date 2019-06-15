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

int arr[1500];
int tot[15];
int tot2[15];

int main(){
	desperate_optimization(10);
	int n;
	int tc = 0;
	while(cin>>n) {
		tc++;
		if(n == 0) break;
		cout<<"Game "<<tc<<":"<<endl;
		memset(tot,0,sizeof(tot));
		for(int i = 0;i < n;i++) {
			cin>>arr[i];
			tot[arr[i]]++;
		}
		while(1) {
			int tota =0, totb = 0;
			memset(tot2,0,sizeof(tot2));
			for(int i = 0;i < n;i++) {
				int x;
				cin>>x;
				tot2[x]++;
				if(x == arr[i])tota++;
			}
			for(int i = 1;i <= 9;i++) totb += min(tot[i],tot2[i]);
			if(tot2[0] == n) break;
			totb -= tota;
			cout<<"    ("<<tota<<","<<totb<<")\n";
		}
	}
	return 0;
}

