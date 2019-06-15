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

struct point{
	int x,y;
};

vector<point> p1,p2;

int main(){
	srand(time(NULL));
	int n1,n2;
	while(scanf("%d",&n1) != EOF){
		if(n1 == 0) break;
		p1.clear(),p2.clear();
		for(int i=0;i<n1;i++){
			point t;
			scanf("%d %d",&t.x,&t.y);
			p1.pb(t);
		}
		scanf("%d",&n2);
		for(int i=0;i<n2;i++){
			point t;
			scanf("%d %d",&t.x,&t.y);
			p2.pb(t);
		}
		int sz1 = p1.size(),sz2 = p2.size();
		int mini = 1e9;
		if(sz1 * sz2 < 1e6){
			for(int i=0;i<sz1;i++){
				for(int j=0;j<sz2;j++){
					mini = min(mini,abs(p1[i].x - p2[j].x) + abs(p1[i].y - p2[j].y));
				}
			}
		}
		else{
			int k = 1e6;
			for(int i=0;i<k;i++){
				int A = rand()%n1;
				int B = rand()%n2;
				mini = min(mini,abs(p1[A].x - p2[B].x) + abs(p1[A].y - p2[B].y));
			}
		}
		printf("%d\n",mini);
	}
	return 0;
}

