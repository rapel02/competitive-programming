//Template Jollybee 2017-0720 ver.1
#include<stdio.h>
#include<iostream>

#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<string>
#include<cmath>
#include<sstream>

#include<time.h>

#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
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

int in[50005],out[50005],depth[50005];
int BIT[50005];
int par[20][50005];
int N;
vector<int> vec[50005];
int idx = 0;

void traverse(int pos,int dep,int p){
	depth[pos] = dep;
	par[0][pos] = p;
	in[pos] = ++idx;
	for(int i=0;i<vec[pos].size();i++){
		int nx = vec[pos][i];
		if(in[nx] != 0) continue;
		traverse(nx,dep+1,pos);
	}
	out[pos] = idx;
}

void build(){
	ll x = 2;
	for(int i=1;x*2<=N;x*=2,i++){
		for(int j=1;j<=N;j++){
			par[i][j] = par[i-1][par[i-1][j]];
		}
	}
}

int LCA(int x,int y){
	if(depth[x] < depth[y]) swap(x,y);
	int diff = depth[x] - depth[y];
	for(int i=0;diff > 0 ;i++){
		if(diff &(1<<i)){
			x = par[i][x];
			diff -= (1<<i);
		}
	}
	if(x == y) return x;
	for(int i=20;i>=0;i--){
		if(depth[x] >= (1<<i) && par[i][x] != par[i][y]){
			x = par[i][x];
			y = par[i][y];
		}
	} 
	return par[0][x];
}


void update(int idx,int v){
	if(idx == 0) return ;
	for( ;idx<=N;idx+=(idx&(-idx))) BIT[idx] += v;
}

int query(int idx){
	int ans = 0;
	for(;idx>0;idx-=(idx & (-idx))) ans += BIT[idx];
	return ans;
}

void update(int x,int y,int v){
	update(in[x],v);
	update(in[y],v);
	int tar = LCA(x,y);
	update(in[tar],-v);
	update(in[par[0][tar] ],-v);
}

int main(){
	int ntc;
	scanf("%d",&ntc);
	for(int tc=1;tc<=ntc;tc++){
		scanf("%d",&N);
		idx = 0;
		memset(depth,-1,sizeof(depth));
		memset(in,0,sizeof(in));
		memset(par,0,sizeof(par));
		memset(BIT,0,sizeof(BIT));
		for(int i=1;i<N;i++){
			int x,y;
			scanf("%d %d",&x,&y);
			vec[x+1].pb(y+1);
			vec[y+1].pb(x+1);
		}
		traverse(1,1,0);
		build();
		int q;
		printf("Case #%d:\n",tc);
		scanf("%d",&q);
		for(int i=0;i<q;i++){
			int x,y,v;
			scanf("%d %d %d",&x,&y,&v);
			update(x+1,y+1,v);
		}
		for(int i=1;i<=N;i++){
			printf("%d\n",query(out[i]) - query(in[i] -1));
		}
		for(int i=1;i<=N;i++) vec[i].clear();
	}
	return 0;
}

