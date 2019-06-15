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

int n,m;

struct monkey{
	int v,l,r;
}mon[105];

struct edge{
	int l,r;
}E[1005];

int flow[505][505],rflow[505][505];
int level[500];
vector<int> vec[505];
pair<int,int> val[505];
vector<pair<int,int> > vans[505];

bool BFS(int s,int f){
	memset(level,-1,sizeof(level));
	level[s] = 0;
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		int pos = q.front();
		q.pop();
		for(int i=0;i<vec[pos].size();i++){
			int nx = vec[pos][i];
			if(level[nx] != -1 || flow[pos][nx] == 0) continue;
			level[nx] = level[pos] + 1;
			q.push(nx);
		}
	}
	return level[f] != -1;
}

int sendFlow(int s,int f,int flowNow){
	if(s == f) return flowNow;
	for(int i=0;i<vec[s].size();i++){
		int nx = vec[s][i];
		if(level[s] + 1 == level[nx] && flow[s][nx] != 0){
			int tempFlow = min(flowNow,flow[s][nx]);
			int send = sendFlow(nx,f,tempFlow);
			if(send > 0){
				flow[s][nx] -= send;
				flow[nx][s] += send;
				return send;
			}
		}
	}
	return 0;
}
int k;
void backtrack(int pos,int idx){
	if(idx != -1){
		vans[idx].pb(val[pos]);
		return ;
	}
	for(int i=pos + 1;i<= n + k + 1;i++){
		if(flow[pos][i] != rflow[pos][i]){
			backtrack(i,(pos == 0)?-1:pos);
		}
	}
	return ;
}

int main(){
	int ntc = 0;
	while(scanf("%d",&n)!=EOF){
		if(n == 0) break;
		for(int i=0;i<505;i++) vec[i].clear(),vans[i].clear();
		memset(flow,0,sizeof(flow));
		memset(rflow,0,sizeof(rflow));
		scanf("%d",&m);
		set<int> s;
		int all = 0;
		for(int i=1;i<=n;i++){
			scanf("%d %d %d",&mon[i].v,&mon[i].l,&mon[i].r);
			all += mon[i].v;
			s.insert(mon[i].l);
			s.insert(mon[i].r);
		}
		k = 0;
		for(set<int>::iterator it = s.begin();it!=s.end();){
			int v1 = *it;
			it++;
			if(it == s.end()) break;
			int v2 = *it;
			bool mid = false;
			for(int i=1;i<=n;i++){
				if(mon[i].l <= v1 && v2 <= mon[i].r) mid = true;
			}
			if(mid == true){
				k++;
				E[k].l = v1;
				E[k].r = v2;
				val[n + k] = mp(v1,v2);
			}
		}
		for(int i=1;i<=n;i++){
			vec[i].pb(0);
			vec[0].pb(i);
			flow[0][i] = mon[i].v;
			rflow[0][i] = flow[0][i];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k;j++){
				if(mon[i].l <= E[j].l && E[j].r <= mon[i].r){
					flow[i][n+j] = E[j].r - E[j].l;
					rflow[i][n+j] = flow[i][n+j];
					vec[i].pb(n + j);
					vec[n + j].pb(i);
				}
			}
		}
		for(int j=1;j<=k;j++){
			vec[n + k + 1].pb(n + j);
			vec[n + j].pb(n + k + 1);
			flow[n + j][n + k + 1] = (E[j].r - E[j].l) * m;
			rflow[n + j][n + k + 1] = flow[n + j][n + k + 1];
		}
		int tot = 0;
		while(BFS(0,n + k + 1) == true){
			while(int f = sendFlow(0,n + k + 1,1e9)){
				tot += f;
				//printf("%d %d\n",f,tot);
				if(f == 0) break;
			}
		}
		printf("Case %d: ",++ntc);
		if(tot != all) printf("No\n");
		else{
			printf("Yes\n");
			backtrack(0,-1);
			for(int i=1;i<=n;i++){
				sort(vans[i].begin(),vans[i].end());
				printf("%d",vans[i].size());
				
				for(int j=0;j<vans[i].size();j++){
					int red = vans[i][j].fi + min(mon[i].v,vans[i][j].se - vans[i][j].fi);
					printf(" (%d,%d)",vans[i][j].fi,red);
					mon[i].v -= red;
				}
				printf("\n");
			}
		}
	}
	return 0;
}

