#include<bits/stdc++.h>
using namespace std;

int arr[30][30];
bool vis[30][30];
int tot[30][30];
int ans;

int px[] = {1,-1};
int py[] = {1,-1};
int n;

void floodfill(int y,int x)
{
	if(vis[y][x]==true) return ;
	vis[y][x] = true;
	for(int a=0;a<2;a++)
	{
		for(int b=0;b<2;b++)
		{
			int yy = y + py[a];
			int xx = x + px[b];
			if(yy<0 || xx<0 || yy>=n || xx>=n )continue;
			if(arr[yy][xx]==0)
			{
				ans++;
				arr[yy][xx] = 1;
			}
			floodfill(yy,xx);
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
		for(int a=0;a<n;a++)
			for(int b=0;b<n;b++) scanf("%d",&arr[a][b]);
		printf("Case %d: ",ntc);	
		memset(vis,false,sizeof(vis));
		memset(tot,0,sizeof(tot));
		ans = 0;
		for(int a=0;a<n;a++)
		{
			for(int b=0;b<n;b++)
			{
				if(arr[a][b]==1 && vis[a][b]==false)
				{
					floodfill(a,b);
				}
			}
		}
		for(int a=0;a<n;a++)
		{
			for(int b=0;b<n;b++)
			{
				if(a!=0) tot[a][b]+=arr[a-1][b];
				if(a!=n-1) tot[a][b]+=arr[a+1][b];
				if(b!=0) tot[a][b]+= arr[a][b-1];
				if(b!=n-1) tot[a][b]+= arr[a][b+1];
			}
		}
		bool ada = true;
		for(int a=0;a<n;a++)
			for(int b=0;b<n;b++) if(tot[a][b]%2==1) ada = false;
		if(ada==false) printf("-1\n");
		else printf("%d\n",ans);
	}
}
