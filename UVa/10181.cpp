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

int arr[5][5];
bool stats = false;
char ans[55];
bool check(int ro){
	ro = 4 - ro;
	int temp[16];
	int k = 0;
	for(int i=0;i<4;i++) for(int j=0;j<4;j++) temp[k++] = arr[i][j];
	int inv = 0;
	for(int i=0;i<k;i++){
		if(temp[i] == 0) continue;
		for(int j=0;j<i;j++){
			if(temp[i] < temp[j]) inv++;
		}
	}
	return (ro%2 == inv % 2);
}

int py[]={1,0,0,-1};
int px[]={0,1,-1,0};

char dir[]="DRLU";

map<pair<pair<int,int>,pair<int,int> >,int> stt;

int H(){
	int tot_h = 0;
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			int v = arr[i][j];
			if(v == 0) continue;
			v--;
			int rr = v / 4;
			int cc = v % 4;
			tot_h += abs(rr - i) + abs(cc-j);
		}
	}
	return tot_h;
}

int singleH(int y,int x,int v){
	v--;
	int rr = v / 4;
	int cc = v % 4;
	return abs(rr - y) + abs(cc - x);
}

string create(){
	string ans="";
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			ans += (arr[i][j] +'A');
		}
	}
	return ans;
}

bool compute(int depth,int heuristic,int y,int x,int pre){
	//printf("%d %d %d %d\n",depth,heuristic,y,x);
	if(depth + heuristic > 50) return false;
	if(heuristic == 0){
		ans[depth] = '\0';
		printf("%s\n",ans);
		stats = true;
		return true;
	}
	//if(stt[mp(mp(depth,heuristic),mp(y,x))] == 1) return false;
	//stt[mp(mp(depth,heuristic),mp(y,x))] = 1;
	//priority_queue<pair<int,int> > pq;
//	for(int i=0;i<4;i++){
//		for(int j=0;j<4;j++) printf("%d ",arr[i][j]);
//		printf("\n");
//	}
//	getchar();
	for(int i=0;i<4;i++){
		if(pre + i == 3) continue;
		int yy = py[i] + y;
		int xx = px[i] + x;
		if(yy < 0 || xx < 0 || yy > 3 || xx > 3) continue;
		swap(arr[y][x],arr[yy][xx]);
		int new_h = heuristic - singleH(yy,xx,arr[y][x]) + singleH(y,x,arr[y][x]);
		//int new_h = H();
		ans[depth] = dir[i];
		compute(depth + 1,new_h,yy,xx,i);
		//string v = create();
		//if(stt[v] == false) pq.push(mp(-new_h,i));
		//stt[v] = true;
		swap(arr[y][x],arr[yy][xx]);
		if(stats==true) return true;
	}
//	while(!pq.empty()){
//		int idx = pq.top().se;
//		int new_h = pq.top().fi;
//		pq.pop();
//		int yy = py[idx] + y;
//		int xx = px[idx] + x;
//		ans[depth] = dir[idx];
//		swap(arr[y][x],arr[yy][xx]);
//		compute(depth + 1,new_h,yy,xx);
//		swap(arr[y][x],arr[yy][xx]);
//		if(stats==true) return true;
//	}
	return false;
}

int main(){
	int tc;
	scanf("%d",&tc);
	while(tc--){
		//stt.clear();
		stats = false;
		for(int i=0;i<4;i++) for(int j=0;j<4;j++) scanf("%d",&arr[i][j]);
		int sy,sx;
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++) if(arr[i][j] == 0) sy = i, sx = j;
		}
		if(check(sy)) printf("This puzzle is not solvable.\n");
		else{
			compute(0,H(),sy,sx,-1);
		}
	}
}
