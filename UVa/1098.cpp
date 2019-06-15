#include<bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
using namespace std;

long long tot = 0;
int r,c;
bool vis[10][10];
int cr[5],cc[5];
int mv[66];
int pcr[5],pcc[5];
int p[15][15];
int py[]={1,-1,0,0};
int px[]={0,0,1,-1};
queue<pair<int,int> > q;

int bfs()
{
	bool arr[10][10];
	for(int a=0;a<8;a++) for(int b=0;b<8;b++) arr[a][b] = vis[a][b];
	int tot = 0;
	if(arr[0][1]==false) q.push(mp(0,1));
	arr[0][1] = true;
	while(!q.empty())
	{
		int y = q.front().ff;
		int x = q.front().ss;
		q.pop();
		tot++;
		for(int a=0;a<4;a++)
		{
			int yy = py[a] + y;
			int xx = px[a] + x;
			if(yy<0 || xx<0 || yy>=r || xx>=c) continue;
			if(arr[yy][xx]==true) continue;
			arr[yy][xx] = true;
			q.push(mp(yy,xx));
		}
	}
	return tot;
}


void backtrack(int y,int x,int stp, int now)
{
	//printf("insert: %d %d %d %d\n",y,x,stp,now);
	vis[y][x]=true;
	//printf("%d %d\n",p[y][x],mv[p[y][x]]);
	if(p[y][x]!=-1 && mv[p[y][x]]==stp) now++;
	//printf("success\n");
	if(now==5)
	{
		tot++;
		return ;
	}
	for(int a=0;a<4;a++)
	{
		int yy = py[a] + y;
		int xx = px[a] + x;
		int nstp = stp+1;
		//printf("nx move: %d %d %d\n",yy,xx,nstp);
		if(yy<0 || xx<0 || yy>=r || xx>=c) continue;
		//printf("pass 1\n");
		if(vis[yy][xx]==true) continue;
		//printf("%d %d\n",yy,xx);
		if(p[yy][xx]!=-1 && mv[p[yy][xx]]!=nstp) continue;
		//printf("%d %d %d %d wew\n",yy,xx,nstp,now);
		//printf("%d %d\n",mv[now] - nstp , abs(cr[now] - yy) + abs(cc[now] - xx));
		if(mv[now]- nstp < 0) continue;
		if(mv[now] - nstp < abs(cr[now] - yy) + abs(cc[now] - xx)) continue;
		vis[yy][xx] = true;
		//printf("%d %d %d\n",bfs(vis),nstp,r*c);
		if(bfs()+nstp==r*c) backtrack(yy,xx,nstp,now);
		vis[yy][xx] = false;
	}
}


int main()
{
	int tc=0;
	while(1)
	{
		tc++;
		scanf("%d %d",&r,&c);
		tot=0;
		if(r==0 && c==0) break;
		memset(p,-1,sizeof(p));
		cr[0] = 0,cc[0] = 0,cr[4] = 0,cc[4] = 1;
		for(int a=1;a<=3;a++) scanf("%d %d",&cr[a],&cc[a]);
		for(int a=1;a<=4;a++) p[cr[a]][cc[a]] = a;
		int val = r*c;
		for(int a=1;a<=4;a++) mv[a] = val*a/4;
		bool ada = true;
		//for(int a=1;a<=4;a++) printf("%d ",mv[a]);
		for(int a=2;a<=4;a++)
		{
			//printf("%d %d\n",mv[a]-mv[a-1] ,abs(cr[a] - cr[a-1]) + abs(cc[a] - cc[a-1]));
			if(mv[a]-mv[a-1] < abs(cr[a] - cr[a-1]) + abs(cc[a] - cc[a-1])) ada = false;
		}
		if(ada)
		{
			backtrack(0,0,1,1);
		}
		printf("Case %d: %lld\n",tc,tot);
	}
}
