//Template Jollybee 2017-0720 ver.1
#include<stdio.h>
#include<iostream>
#include<sstream>

#include<string.h>
#include<algorithm>
#include<string>
#include<math.h>

#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>

#include<stdlib.h>
#include<assert.h>
#include<time.h>

using namespace std;
//include isi sendiiri

//typedef pakai huruf kecil semua
typedef long long ll;
typedef unsigned long long ull;

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<pii> vii;

const int /* ato ll */ INF=(int)2e9; //tergantung soalnya
const double EPS=(double)1e-9;
const double PI=(double)acos(-1.0);
const ll MOD=(ll)1e9+7; //tergantung soalnya

//Macro yang umum
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front

//increasing
#define FOR(i,n) for(int i=0;i<n;i++)
#define REPP(i,l,r,c) for(int i=l;i<=r;i+=c)
#define REP(i,l,r) REPP(i,l,r,1)

//decreasing
#define FORD(i,n) for(int i=n-1;i>=0;i--)
#define REVV(i,l,r,c) for(int i=max(l,r),_m=min(l,r);i>=_m;i-=c)
#define REV(i,l,r) REVV(i,l,r,1)

//memset pakai std::fill

//random
int irand(int lo, int hi){
	return (((double)rand())/(RAND_MAX+1.0)) * (hi-lo+1) + lo;
}

//ll to string
string toString(ll x) {
	stringstream ss;
	ss << x;
	return ss.str();
}

//string to ll
ll toNumber(string S) {
	ll ret;
	sscanf(S.c_str(),"%lld",&ret);
	return ret;
}

//end of template
typedef unsigned long long ull;
vector<ull> v;
ull num[68000];

void pre(){
	num[1] = 1;
	for(ull i=2;i<=66000;i++){
		if(num[i] == 0){
			for(ull j= i*i;j<=66000;j+=i) num[j] = i;
		}
	}
	for(ull i=2;i<=66000;i++){
		//if(num[i] != 0) continue;
		int idx = 1;
		ull mul = i;
		ull pre = 1;
		while(pre <= mul){
			if(idx != 1 && num[idx] != 0){
				if(mul != 0) v.pb(mul);
			}
			mul *= i;
			if((idx * log2(i*1.0)) >= 64.0) break;
			pre *= i;
			idx++;
		}
	}
	v.pb(1);
	set<ull> s(v.begin(),v.end());
	v.assign(s.begin(),s.end());
}

int main(){
	pre();
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<endl;
	//	getchar();
	}
	return 0;
}

