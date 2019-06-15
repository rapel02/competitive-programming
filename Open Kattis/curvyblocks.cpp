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

double b[4],t[4];
double it[4];

double f(double x){
	return t[0] + t[1] * x + t[2] * x * x + t[3] * x * x * x;
}

int main(){
	desperate_optimization(10);
	while(cin>>b[0]){
		for(int i=1;i<4;i++) cin>>b[i];
		for(int i=0;i<4;i++) cin>>t[i];
		for(int i=0;i<4;i++) t[i] -= b[i];
		for(int i=3;i>=1;i--){
			it[i-1] = i * t[i];
		}
		double A = it[2];
		double B = it[1];
		double C = it[0];
		double D = B * B - 4 * A * C;
		double x3 = -1,x2 = -1;
		if(D >= 0){
			x3 = (-B + sqrt(D))/(2.0 * A);
			x2 = (-B - sqrt(D))/(2.0 * A);			
		}
		double x0 = 0;
		double x1 = 1;
		double maxi = max(f(x0),f(x1));
		double mini = min(f(x0),f(x1));
		if(x0 < x2 && x2 < x1) maxi = max(maxi,f(x2)), mini = min(mini,f(x2));
		if(x0 < x3 && x3 < x1) maxi = max(maxi,f(x3)), mini = min(mini,f(x3));
		cout<<maxi-mini<<endl;
	}
	return 0;
}

