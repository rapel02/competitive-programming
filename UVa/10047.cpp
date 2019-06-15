#include<bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
using namespace std;

char field[30][30];

int vis[30][30][6][5];

int px[]={0,1,0,-1};
int py[]={-1,0,1,0};

queue<pair<pair<int,int> ,pair<int,int> > > q;

/*
0 N, 1 E,2 S,3 W
*/

int main()
{
	int tc = 0;
	while(1)
	{
		int r,c;
		tc++;
		scanf("%d %d",&r,&c);
		if(r+c==0) break;
		if(tc!=1) printf("\n");
		for(int a=0;a<r;a++) scanf("%s",field[a]);
		memset(vis,-1,sizeof(vis));
		for(int a=0;a<r;a++)
		{
			for(int b=0;b<c;b++)
			{
				if(field[a][b]=='S')
				{
					vis[a][b][0][0] = 0;
					q.push(mp(mp(a,b),mp(0,0)));
				}
			}
		}
		int ans = 2000000000;
		while(!q.empty())
		{
			int yy = q.front().ff.ff;
			int xx = q.front().ff.ss;
			int cl = q.front().ss.ff;
			int dr = q.front().ss.ss;
			int stp = vis[yy][xx][cl][dr];
			q.pop();
			if(field[yy][xx]=='T' && cl==0) ans = min(ans,stp);
			int y = py[dr] + yy;
			int x = px[dr] + xx;
			if(!(x<0 || y<0 || x>=c || y>=r))
			{
				if(field[y][x]!='#')
				{
					if(vis[y][x][(cl+1)%5][dr]==-1)
					{
						vis[y][x][(cl+1)%5][dr] = stp+1;
						q.push(mp(mp(y,x),mp((cl+1)%5,dr)));
					}
				}
			}
			if(vis[yy][xx][cl][(dr+3)%4]==-1)
			{
				vis[yy][xx][cl][(dr+3)%4] = stp+1;
				q.push(mp(mp(yy,xx),mp(cl,(dr+3)%4)));
			}
			if(vis[yy][xx][cl][(dr+1)%4]==-1)
			{
				vis[yy][xx][cl][(dr+1)%4] = stp+1;
				q.push(mp(mp(yy,xx),mp(cl,(dr+1)%4)));
			}
		}
		printf("Case #%d\n",tc);
		if(ans==2000000000) printf("destination not reachable\n");
		else printf("minimum time = %d sec\n",ans);
	}
}
