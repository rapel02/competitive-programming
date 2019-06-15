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

vector<pair<int,int> > vec[150];

int cost[150][150][2];
int flow[150][150][2];
int dist[150];
pair<int,int> par[150];
int ct = 0, path = 0;

bool bellman(int N){
	for(int i=1;i<=N;i++) dist[i] = 1e9;
	dist[1] = 0;
	for(int i=1;i<N;i++){
		for(int j=1;j<=N;j++){
			for(int k=0;k<vec[j].size();k++){
				int nx = vec[j][k].fi;
				int dir = vec[j][k].se;	
				if(flow[j][nx][dir] != 0){
					if(dist[nx] > dist[j] + cost[j][nx][dir]){
						dist[nx] = dist[j] + cost[j][nx][dir];
						par[nx] = mp(j,dir);
					}
				}
			}
		}
	}
	if(dist[N] == 1e9) return false;
	path += dist[N];
	return true;
}

int augment(int pos,int mini){
	if(pos == 1) return mini;
	int prev = par[pos].fi;
	int dir = par[pos].se;
	int mi = augment(prev,min(mini,flow[prev][pos][dir]));
	flow[prev][pos][dir] -= mi;
	flow[pos][prev][dir] += mi;
	return mi;
}

int main(){
	int N,M;
	while(scanf("%d",&N)!=EOF){
		path = 0;
		ct = 0;
		if(N == 0) break;
		scanf("%d",&M);
		for(int i=0;i<=N;i++) vec[i].clear();
		memset(cost,0,sizeof(cost));
		memset(flow,0,sizeof(flow));
		for(int i=1;i<=M;i++){
			int x,y,v;
			scanf("%d %d %d",&x,&y,&v);
			vec[x].pb(mp(y,1));
			vec[x].pb(mp(y,0));
			cost[x][y][1] = cost[y][x][0] = v;
			flow[x][y][1] = flow[y][x][0] = 1;
			cost[x][y][0] = cost[y][x][1] = -v;
			flow[x][y][0] = flow[y][x][1] = 0;
			vec[y].pb(mp(x,0));
			vec[y].pb(mp(x,1));
		}
		while(ct < 2 && bellman(N)==true){
			ct += augment(N,1e9);
		}
		//printf("%d %d\n",ct,path);
		if(ct < 2) printf("Back to jail\n");
		else printf("%d\n",path);
	}
	return 0;
}

