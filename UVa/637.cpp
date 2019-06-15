#include <stdio.h>
#include <iostream>
#include <sstream>
#include <iomanip>

#include <algorithm>
#include <stdlib.h>
#include <cstdlib>
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

int n;

int main(){
	desperate_optimization(10);
	int n;
	while(cin>>n) {
		if(n == 0) break;
		int k = n / 4;
		k *= 4;
		if(n % 4 != 0) k += 4;
		cout<<"Printing order for "<<n<<" pages:\n";
		int sheet = 1;
		int flag = 0;
		int lo = 1;
		int hi = k;
		while(lo <= hi) {
			if(lo > n) break;
			int ada = hi;
			if(hi > n) ada = 0;
			int cetak = lo;
			if(flag == 0) swap(cetak,ada);
			cout<<"Sheet "<<sheet<<", "<<((flag == 0)?"front":"back ")<<": ";
			if(cetak == 0) cout<<"Blank";
			else cout<<cetak;
			cout<<", ";
			if(ada == 0) cout<<"Blank";
			else cout<<ada;
			cout<<endl;
			flag ^= 1;
			if(flag == 0) sheet++;
			lo++,hi--;
		}
	}
	return 0;
}

