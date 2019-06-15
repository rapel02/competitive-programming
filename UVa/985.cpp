#include<bits/stdc++.h>
#define mp make_pair
#define ff first
#define ss second
using namespace std;

int pos[550][550][5];

vector<int> vec[550][550];

char in[15];

queue<pair<int,pair<int,int> > > q;

int py[]={-1,0,1,0};
int px[]={0,1,0,-1};

int main()
{
	int r,c;
	while(scanf("%d %d",&r,&c)!=EOF)
	{
		for(int a=0;a<r;a++)
		{
			for(int b=0;b<c;b++)
			{
				if(a==r-1 && b==c-1) continue;
				scanf("%s",in);
				int len = strlen(in);
				for(int d=0;d<len;d++)
				{
					int num = 0;
					if(in[d]=='N') num = 0;
					if(in[d]=='E') num = 1;
					if(in[d]=='S') num = 2;
					if(in[d]=='W') num = 3;
					vec[a][b].push_back(num);
				}
			}
		}
		memset(pos,-1,sizeof(pos));
		q.push(mp(0,mp(0,0)));
		pos[0][0][0] = 0;
		int ans = 2000000000;
		while(!q.empty())
		{
			int stp = q.front().ff;
			int y = q.front().ss.ff;
			int x = q.front().ss.ss;
			//printf("%d %d %d %d\n",y,x,stp,stp%4);
			q.pop();
			if(y==r-1 && x==c-1) ans = min(ans,stp);
			int sz = vec[y][x].size();
			int add = stp%4;
			for(int a=0;a<sz;a++)
			{
				int v = (vec[y][x][a] + add)%4;
				int yy = y + py[v];
				int xx = x + px[v];
				//printf("%d %d %d\n",vec[y][x][a],yy,xx);
				if(yy<0 || xx<0 || yy>=r || xx>=c) continue;
				if(pos[yy][xx][(add+1)%4]!=-1) continue;
				pos[yy][xx][(add+1)%4] = stp + 1;
				q.push(mp(stp+1,mp(yy,xx)));
			}
		}
		if(ans==2000000000) printf("no path to exit\n");
		else printf("%d\n",ans);
		for(int a=0;a<r;a++) for(int b=0;b<c;b++) vec[a][b].clear();
	}
	
}
