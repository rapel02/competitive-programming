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

const int MAXN = 36;

map<ll,int> mmap;
int arr[7],nx[7];
ll val[MAXN][MAXN];
int p[]={1,-1};
ll mx[MAXN];

struct matrix{
	ll x[MAXN][MAXN];
};

matrix ans,A,C;
void backtrack(int va,int idx){
	if(idx == 7){
		int tar = 0;
		for(int i=0;i<7;i++) tar = tar * 10 + nx[i];
		int idx1 = mmap[va] - 1;
		int idx2 = mmap[tar] - 1;
		val[idx2][idx1] = 1;
		return ;
	}
	if(arr[idx] == 0) backtrack(va,idx+1);
	else{
		for(int i=0;i<2;i++){
			int put = idx + p[i];
			if(put < 0 || put > 6) continue;
			if(nx[put] != 0) continue;
			nx[put] = arr[idx];
			backtrack(va,idx+1);
			nx[put] = 0;
		}
	}
	return ;
}

void pre(){
	for(int i=0;i<4;i++) arr[i] = 1;
	sort(arr,arr+7);
	int idx = 0;
	do{
		int tmp = 0;
		for(int i=0;i<7;i++) tmp = tmp * 10 + arr[i];
		if(mmap[tmp] == 0)mmap[tmp] = ++idx;
	}while(next_permutation(arr,arr+7));
	sort(arr,arr+7);
	int iw = 0;
	do{
		int tmp = 0;
		for(int i=0;i<7;i++) tmp = tmp * 10 + arr[i],nx[i] = 0;
		backtrack(tmp,0);
	}while(next_permutation(arr,arr+7));
}

matrix mul(matrix A,matrix B){
	int i,j,k;
	for(i = 0;i<MAXN;i++){
		for(j=0;j<MAXN;j++){
			C.x[i][j] = 0;
			for(k = 0;k < MAXN;k++){
				C.x[i][j] = (C.x[i][j] + A.x[i][k] *B.x[k][j])%MOD;
			}
		}
	}
	return C;
}

long long comp(int n){
	if(n == 0) return 1;
	for(int i=0;i<MAXN;i++) for(int j=0;j<MAXN;j++) A.x[i][j] = val[i][j];
	for(int i=0;i<MAXN;i++) for(int j=0;j<MAXN;j++) ans.x[i][j] = ((i == j)?1:0);
	int tmp = 0;
	for(int i=0;i<7;i++) tmp = tmp * 10 + ((arr[i] == 0)?0:1);
	int vx = mmap[tmp] - 1;
	memset(mx,0,sizeof(mx));
	mx[vx] = 1;
	//cout<<"HERE"<<endl;
	while(n != 0){
		if(n%2 == 1) ans = mul(ans,A);
		A = mul(A,A);
		n/=2;
	//	cout<<n<<endl;
	}
	ll tot = 0;
	for(int i=0;i<MAXN;i++){
		for(int j=0;j<MAXN;j++){
			tot = (tot + ans.x[j][i] * mx[j]) % MOD;
		}
	}
	return tot;
}

int main(){
	pre();
	int ntc;
	scanf("%d",&ntc);
	while(ntc--){
		int n;
		scanf("%d",&n);
		for(int i=0;i<7;i++) scanf("%d",&arr[i]);
	//	printf("YAY\n");
		printf("%lld\n",comp(n-1));
	}
	return 0;
}

