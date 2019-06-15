#include<stdio.h>
#include<string.h>
#include<vector>
#include<iostream>
#include<algorithm>
#include<string>
#include<math.h>
#include<cstdlib>
using namespace std;

const int MAXN = 555;
vector<int> vec[MAXN];
int diff[MAXN],val[MAXN];
int xa[MAXN],xb[MAXN],ya[MAXN],yb[MAXN];
int pos[MAXN];
bool vis[MAXN];


bool aug(int no)
{
	if(vis[no]==true) return false;
	vis[no] = true;
	for(int a=0;a<vec[no].size();a++)
	{
		int nx = vec[no][a];
		if(pos[nx] == -1 || aug(pos[nx]) == true)
		{
			pos[nx] = no;
			return true;
		}
	}
	return false;
}

int MCBM(int n)
{
	memset(pos,-1,sizeof(pos));
	int ans = 0;
	for(int a=1;a<=n;a++)
	{
		memset(vis,false,sizeof(vis));
		if(aug(a) == true) ans++;
	}
	return ans;
}

int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		int n;
		scanf("%d",&n);
		int V = n;
		for(int a=0;a<n;a++)
		{
			int h,m;
			scanf("%d:%d %d %d %d %d",&h,&m,&xa[a],&ya[a],&xb[a],&yb[a]);
			diff[a] = abs(xa[a] - xb[a]) + abs(ya[a] - yb[a]);
			val[a] = h*60 + m;
		}
		for(int a=0;a<n;a++)
		{
			for(int b=a+1;b<n;b++)
			{
				//if(a == b) continue;
				int re = abs(xb[a] - xa[b]) + abs(yb[a] - ya[b]);
				if(val[b] > val[a] + diff[a] + re) vec[a+1].push_back(b+1);
			}
		}
		int ans = MCBM(V);
		printf("%d\n",V - ans);
		for(int a=0;a<MAXN;a++) vec[a].clear();
	}
}
