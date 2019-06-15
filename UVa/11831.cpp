#include<bits/stdc++.h>
using namespace std;

char in[150][150];
char moveset[50005];

int py[]={-1,0,1,0};
int px[]={0,1,0,-1};

int r,c,pos;

bool isvalid(int y,int x)
{
	if(y<0 ||x<0 ||y>=r || x>=c || in[y][x]=='#') return false;
	return true;
}

int main()
{
	while(1)
	{
		scanf("%d %d %d",&r,&c,&pos);
		if(r+c+pos==0) break;
		int sx = 0;
		int sy = 0;
		int id = 0;
		for(int a=0;a<r;a++)
		{
			scanf("%s",in[a]);
			for(int b=0;b<c;b++)
			{
				if(in[a][b]=='N')
				{
					sx = b;
					sy = a;
					id = 0;
				}
				if(in[a][b]=='S')
				{
					sx = b;
					sy = a;
					id = 2;
				}
				if(in[a][b]=='L')
				{
					sx = b;
					sy = a;
					id = 1;
				}
				if(in[a][b]=='O')
				{
					sx = b;
					sy = a;
					id = 3;
				}
			}
		}
		scanf("%s",moveset);
		int tot = 0;
		for(int a=0;a<pos;a++)
		{
			if(moveset[a]=='F')
			{
				if(isvalid(sy+py[id],sx+px[id]))
				{
					sy=sy+py[id];
					sx=sx+px[id];
					if(in[sy][sx]=='*')
					{
						tot++;
						in[sy][sx] = '.';
					}
				}
			}
			else if(moveset[a]=='E')
			{
				id = (id+3)%4;
			}
			else if(moveset[a]=='D')
			{
				id = (id+1)%4;
			}
		}
		printf("%d\n",tot);
	}
}
