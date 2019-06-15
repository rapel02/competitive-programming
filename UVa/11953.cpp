#include<bits/stdc++.h>
using namespace std;

int n;
bool vis[150][150];
char f[150][150];
int py[] = {0,0,1,-1};
int px[] = {1,-1,0,0};

void rec(int y,int x)
{
	if(y<0 || x<0 || x>=n || y>=n) return ;
	if(f[y][x]=='.') return ;
	if(vis[y][x]==true) return ;
	vis[y][x] = true;
	for(int a=0;a<4;a++)
	{
		for(int b=0;b<4;b++)
		{
			rec(y+py[a],x+px[b]);
		}
	}
}

int main()
{
	int tc;
	scanf("%d",&tc);
	for(int ntc=1;ntc<=tc;ntc++)
	{
		scanf("%d",&n);
		for(int a=0;a<n;a++) scanf("%s",f[a]);
		int ans = 0;
		memset(vis,false,sizeof(vis));
		for(int a=0;a<n;a++)
		{
			for(int b=0;b<n;b++)
			{
				if(f[a][b]=='x' && vis[a][b] ==false)
				{
					ans++;
					rec(a,b);
				}
			}
		}
		printf("Case %d: %d\n",ntc,ans);
	}
}
