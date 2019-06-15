#include<bits/stdc++.h>
using namespace std;

char ff[55][55];
bool vis[55][55];
int ans = 0,tot = 0;
int r,c;

void rec(int a,int b)
{
	if(vis[a][b]==true) return ;
	vis[a][b] = true;
//	printf("%d %d\n",a,b);
	tot++;
	for(int s=-1;s<=1;s++)
		for(int t=-1;t<=1;t++)
		{
			if(s==0 && t==0) continue;
			int xx = s + b;
			int yy = t + a;
			if(xx<0 || yy<0 || xx>= c||yy>=r) continue;
			if(ff[yy][xx]!='1') continue;
			if(vis[yy][xx]==false) rec(yy,xx);
		}
	return ;
}

int main()
{
	int tc;
	scanf("%d",&tc); getchar(); getchar();
	bool first = true;
	while(tc--)
	{
		if(!first) printf("\n");
		first = false;
		ans = 0;
		int a=0,b=0;
		r=0,c=0;
		for(int a=0;a<30;a++)
			for(int b=0;b<30;b++)
				ff[a][b] = '\0';
		while(1)
		{
			char temp;
			c = max(c,b);
			scanf("%c",&temp);
			if(temp=='\n')
			{
				if(b==0) break;
				a++,b=0;
			}
			else ff[a][b] = temp,b++;
		}
		r = a;
		memset(vis,false,sizeof(vis));
		for(int a=0;a<r;a++)
			for(int b=0;b<c;b++)
			{
			//	printf("now: %d %d\n",a,b);
				if(ff[a][b]=='1' && vis[a][b]==false)
				{
			//		printf("in\n");
					tot = 0;
					rec(a,b);
					ans = max(ans,tot);
				}
			}
		printf("%d\n",ans);
	}
}
