#include<bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
using namespace std;


bool vis[10];
int path[16];
vector<pair<int,int> > vec[10];

bool cmp(pair<int,int> A,pair<int,int> B)
{
	return A.ff < B.ff;
}

void pre()
{
	vec[1].pb(mp(2,1));
	vec[2].pb(mp(1,1));
	vec[1].pb(mp(3,2));
	vec[3].pb(mp(1,2));
	vec[2].pb(mp(3,3));
	vec[3].pb(mp(2,3));
	vec[1].pb(mp(5,4));
	vec[5].pb(mp(1,4));
	vec[2].pb(mp(5,5));
	vec[5].pb(mp(2,5));
	vec[3].pb(mp(5,6));
	vec[5].pb(mp(3,6));
	vec[4].pb(mp(3,7));
	vec[3].pb(mp(4,7));
	vec[4].pb(mp(5,8));
	vec[5].pb(mp(4,8));
	for(int a=1;a<=5;a++) sort(vec[a].begin(),vec[a].end(),cmp);
}

void rec(int pos,int step)
{
	path[step] = pos;
	if(step==8)
	{
		for(int a=0;a<=step;a++) printf("%d",path[a]);
		printf("\n");
		return ;
	}
	for(int a=0;a<vec[pos].size();a++)
	{
		int nx = vec[pos][a].ff;
		int val = vec[pos][a].ss;
		if(vis[val]==false)
		{
			vis[val] = true;
			rec(nx,step + 1);
			vis[val] = false;
		}
	}
}

int main()
{
	pre();
	rec(1,0);
}
