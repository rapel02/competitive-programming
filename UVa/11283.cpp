#include<bits/stdc++.h>
using namespace std;

char in[8][8];
char temp[20];

bool vis[10][10];
int len;


bool dfs(int y,int x,int val)
{
	if(len-1==val) return true;
	vis[y][x] = true;
	for(int a=-1;a<=1;a++)
	{
		for(int b=-1;b<=1;b++)
		{
			if(a==0 && b==0) continue;
			int yy = a + y;
			int xx = b + x;
			if(xx < 0 || yy<0 || x>3 || yy>3) continue;
			if(vis[yy][xx]==true) continue;
			if(in[yy][xx]!=temp[val+1]) continue;
			if(dfs(yy,xx,val+1)==true) return true;
		}
	}
	vis[y][x] = false;
	return false;
}

bool isvalid()
{
	memset(vis,false,sizeof(vis));
	for(int a=0;a<4;a++)
	{
		for(int b=0;b<4;b++)
		{
			if(in[a][b]==temp[0]) if(dfs(a,b,0)==true) return true;
		}
	}
	return false;
}

int main()
{
	int ntc;
	scanf("%d",&ntc);
	for(int tc=1;tc<=ntc;tc++)
	{
		for(int a=0;a<4;a++) scanf("%s",in[a]);
		int n;
		scanf("%d",&n);
		int tot = 0;
		for(int a=0;a<n;a++)
		{
			scanf("%s",temp);
			len = strlen(temp);
			if(isvalid())
			{
				if(len==4 || len==3) tot++;
				else if(len==5) tot+=2;
				else if(len==6) tot+=3;
				else if(len==7) tot+=5;
				else tot+=11;
			}
		}
		printf("Score for Boggle game #%d: %d\n",tc,tot);
	}
}
