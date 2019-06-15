#include<bits/stdc++.h>
using namespace std;

char in[150][150],temp[150][150];

int px[]={1,-1,0,0};
int py[]={0,0,1,-1};

int compare(int a,int b,int c,int d)
{
	if(in[a][b]=='R' && in[c][d]=='S') return 1;
	if(in[a][b]=='S' && in[c][d]=='P') return 1;
	if(in[a][b]=='P' && in[c][d]=='R') return 1;
	return 0;
}

int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		int r,c,t;
		scanf("%d %d %d",&r,&c,&t);
		for(int a=0;a<r;a++) scanf("%s",in[a]);
		for(int a=1;a<=t;a++)
		{
			for(int b=0;b<r;b++)
			for(int d=0;d<c;d++) temp[b][d] = '.';
			for(int b=0;b<r;b++)
			{
				for(int d=0;d<c;d++)
				{
					for(int e=0;e<4;e++)
					{
						int y = b + py[e];
						int x = d + px[e];
						if(y < 0 || x<0 || y>=r || x>=c) continue;
						if(compare(b,d,y,x)==1) temp[y][x] = in[b][d];
					}
				}
			}
			for(int b=0;b<r;b++)
			for(int d=0;d<c;d++) if(temp[b][d]=='.') temp[b][d] = in[b][d];
			for(int b=0;b<r;b++)
			for(int d=0;d<c;d++) in[b][d] = temp[b][d];
		}
		for(int a=0;a<r;a++)
		{
			for(int b=0;b<c;b++) printf("%c",in[a][b]);
			printf("\n");
		}
		if(tc!=0) printf("\n");
	}
}
