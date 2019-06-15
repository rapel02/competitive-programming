#include<bits/stdc++.h>
#define mp make_pair
#define ff first
#define ss second
using namespace std;

int vis[55][55][55];
char in[55][55][55];

int pz[]={1,-1,0,0,0,0};
int py[]={0,0,1,-1,0,0};
int px[]={0,0,0,0,1,-1};

queue<pair<int,pair<int,int> > > q;

int main()
{
	while(1)
	{
		int l,r,c;
		scanf("%d %d %d",&l,&r,&c);
		if(l+r+c==0) break;
		memset(vis,-1,sizeof(vis));
		for(int a=0;a<l;a++)
			for(int b=0;b<r;b++) scanf("%s",in[a][b]);
		for(int a=0;a<l;a++)
		{
			for(int b=0;b<r;b++)
			{
				for(int d=0;d<c;d++)
				{
					if(in[a][b][d]=='S') q.push(mp(a,mp(b,d))),vis[a][b][d] = 0;
				}
			}
		}
		int ans = -1;
		while(!q.empty())
		{
			int lv = q.front().ff;
			int rr = q.front().ss.ff;
			int cc = q.front().ss.ss;
			q.pop();
			int stp  =vis[lv][rr][cc];
			if(in[lv][rr][cc]=='E') ans = stp;
			for(int a=0;a<6;a++)
			{
				int nz = lv + pz[a];
				int ny = rr + py[a];
				int nx = cc + px[a];
				if(nz<0 || ny<0 || nx<0 || nz >=l || ny >= r || nx>=c) continue;
				if(in[nz][ny][nx]=='#') continue;
				if(vis[nz][ny][nx]!=-1) continue;
				vis[nz][ny][nx] = stp + 1;
				q.push(mp(nz,mp(ny,nx)));
			}
		}
		if(ans==-1) printf("Trapped!\n");
		else printf("Escaped in %d minute(s).\n",ans);
	}
}
