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
map<int,int> mmap;

ll bitv[225][2000],ans[2000];
int pos[50005];
map<int,int> tot[225];
int arr[50005];

int compute(){
	int tot = 0;
	for(int i=0;i<2000;i++){
		while(ans[i]){
			if(ans[i] & 1) tot++;
			ans[i]/=2;
		}
	}
	return tot;
}

int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	int N = max((int)sqrt(n) + 1,1);
	int x = -1;
	for(int i=0;i<n;i++){
		if(i%N == 0) x++;
		pos[i] = x;
	}
	int k = 1;
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
		if(mmap[arr[i]] == 0) mmap[arr[i]] = k++;
		int cv = mmap[arr[i]];
		tot[pos[i]][cv]++;
		int r = cv/ 60;
		ll c = cv % 60;
		bitv[pos[i]][r] |= (1LL<<c);
	}
	for(int i=0;i<m;i++){
		string in1;
		int x,y;
		cin>>in1;
		scanf("%d %d",&x,&y);
		if(in1=="Q"){
			int px = pos[x] + 1;
			int py = pos[y-1] - 1;
			memset(ans,0,sizeof(ans));
			for(int j=px;j<=py;j++){
				for(int l=0;l<2000;l++) ans[l] |= bitv[j][l];
			}
			for(int l=x;pos[x] == pos[l] && l <= y-1;l++){
				int cv = mmap[arr[l]];
				int r = cv/ 60;
				ll c = cv % 60;
				ans[r] |= (1LL<<c);
			}
			if(pos[y-1] != pos[x]){
				for(int l=y-1;pos[l] == pos[y-1];l--){
					int cv = mmap[arr[l]];
					int r = cv/ 60;
					ll c = cv % 60;
					ans[r] |= (1LL<<c);
				}
			}
			printf("%d\n",compute());
		}
		else{
			if(mmap[y] == 0) mmap[y] = k++;
			int befv = mmap[arr[x]];
			int newv = mmap[y];
			tot[pos[x]][befv]--;
			if(tot[pos[x]][befv] == 0){
				int r = befv / 60;
				ll c = befv % 60;
				bitv[pos[x]][r] &= (~(1LL<<c));
			}
			tot[pos[x]][newv]++;
			int r = newv / 60;
			ll c = newv % 60;
			bitv[pos[x]][r] |= (1LL<<c);
			arr[x] = y;
		}
	}
	return 0;
}

