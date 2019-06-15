#include<bits/stdc++.h>
using namespace std;

char f[25][25];
char water,land;

int py[]={1,-1,0,0};
int px[]={0,0,1,-1};
bool vis[25][25];
int tot = 0;
int ans = 0;
int r,c,r1,c1;

void rec(int y,int x)
{
	tot++;
	for(int a=0;a<4;a++)
	{
		int ny = y + py[a];
		if(ny<0 || ny>=r) continue;
		int nx = (x + px[a] + c) % c;
		if(f[ny][nx]==land) f[ny][nx] = water,rec(ny,nx);
	}
}

int main()
{
	while(scanf("%d %d",&r,&c)!=EOF)
	{
		ans = 0;
		water = '\0';
		land = '\0';
		for(int a=0;a<r;a++) scanf("%s",f[a]);
		scanf("%d %d",&r1,&c1);
		memset(vis,false,sizeof(vis));
		tot = 0;
		land = f[r1][c1];
		for(int a=0;a<r;a++)
			for(int b=0;b<c;b++)
				if(f[a][b]!=land) water = f[a][b];
		f[r1][c1]=water,rec(r1,c1);
		for(int a=0;a<r;a++)
		{
			for(int b=0;b<c;b++)
			{
				tot = 0;
				if(f[a][b]==land) f[a][b]=water,rec(a,b),ans = max(ans,tot);
			}
		}
		printf("%d\n",ans);
		getchar();
	}	
}
