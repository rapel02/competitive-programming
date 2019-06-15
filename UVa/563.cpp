#include<bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
using namespace std;

int px[] = {1,-1,0,0};
int py[] = {0,0,1,-1};

int flow[55][55][2][55][55][2];
queue<pair<int,pair<int,int> > > q;
pair<int,pair<int,int> > par[55][55][2];
bool vis[55][55][2];

void backtrack(int val,int x,int y)
{
	int vval = par[x][y][val].ff;
	int xx = par[x][y][val].ss.ff;
	int yy = par[x][y][val].ss.ss;
	if(xx==-1 && yy==-1) return ;
	flow[xx][yy][vval][x][y][val]--;
	flow[x][y][val][xx][yy][vval]++;
	backtrack(vval,xx,yy);
}

int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		int S,A,B;
		scanf("%d %d %d",&S,&A,&B);
		int T = 2*(S+A);
		if(T < B)
		{
			int x,y;
			for(int a=0;a<B;a++) scanf("%d %d",&x,&y);
			printf("not possible\n");
			continue;
		}
		memset(flow,0,sizeof(flow));
		for(int a=1;a<=S;a++) 
		for(int b=1;b<=A;b++)
		{
			for(int c=0;c<4;c++)
			{
				int aa = a + px[c];
				int bb = b + py[c];
				flow[a][b][0][a][b][1] = 1;
				flow[a][b][1][aa][bb][0] = 1;
			}
		}
		bool ada = true;
		for(int a=0;a<B;a++)
		{
			int x,y;
			scanf("%d %d",&x,&y);
			while(!q.empty()) q.pop();
			memset(vis,false,sizeof(vis));
			par[x][y][0] = mp(-1,mp(-1,-1) );
			vis[x][y][0] = true;
			q.push(mp(0,mp(x,y)));
			bool find = false;
			int rx=-1,ry=-1;
			while(!q.empty())
			{
				int val = q.front().ff;
				int posx = q.front().ss.ff;
				int posy = q.front().ss.ss;
				//printf("%d %d\n",posx,posy);
				if(posx==0 || posy==0 || posx == S+1 || posy == A+1)
				{
					rx = posx;
					ry = posy;
					find = true;
					break;
				}
				q.pop();
				if(flow[posx][posy][val][posx][posy][1^val] <=0) ;
				else if(vis[posx][posy][1^val]==true) ;
				else
				{
					q.push(mp(1^val,mp(posx,posy)));
					par[posx][posy][1^val] = mp(val,mp(posx,posy));
				}
				for(int a=0;a<4;a++)
				{
					int xx = posx + px[a];
					int yy = posy + py[a];
				//	printf("%d %d\n",xx,yy);
					if(vis[xx][yy][1^val]==true) continue;
					if(flow[posx][posy][val][xx][yy][1^val]<=0) continue;
					par[xx][yy][1^val] = mp(val,mp(posx,posy));
					vis[xx][yy][1^val] = true;
					q.push(mp(1^val,mp(xx,yy)) );
				}
			}
			if(find==false) ada = false;
			else backtrack(0,rx,ry);
		}
		if(ada==true) printf("possible\n");
		else printf("not possible\n");
	}
}
