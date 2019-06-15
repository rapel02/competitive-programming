#include<bits/stdc++.h>
using namespace std;

char f[150][150];

bool vis[150][150];
int r,c;
	
void rec(int y,int x)
{
	if(y<0 || x<0 || y>=r || x>=c) return ;
	if(vis[y][x]==true) return ;
	vis[y][x] = true;
	if(f[y][x]!='@') return ;
	for(int a=-1;a<=1;a++)
	{
		for(int b=-1;b<=1;b++)
		{
			rec(y+a,x+b);
		}
	}
	return ;
}

int main()
{
	while(1)
	{
		scanf("%d %d",&r,&c);
		memset(vis,false,sizeof(vis));
		if(r+c==0) break;
		for(int a=0;a<r;a++) scanf("%s",f[a]);
		int tot = 0;
		for(int a=0;a<r;a++)
		{
			for(int b=0;b<c;b++)
			{
				if(vis[a][b]==false && f[a][b]=='@')
				{
					tot++;
					rec(a,b);
				}
			}
		}
		printf("%d\n",tot);
	}
}
