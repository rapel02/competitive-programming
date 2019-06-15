#include<bits/stdc++.h>
#define INF 1e+9
using namespace std;

int dp[10][10][10][10][10][10];

struct val{
	int x[15];
	int price;
}arr[15];

int k;
int n;

int compute(int a,int b,int c,int d,int e,int f)
{
	if(a<0 || b<0 || c<0 || d<0 || e<0 || f<0) return INF;
	if(a==0 && b==0 && c==0 && d==0 &&e==0 &&f==0) return 0;
	if(dp[a][b][c][d][e][f]!=-1) return dp[a][b][c][d][e][f];
	dp[a][b][c][d][e][f] = INF;
	for(int w=0;w<n+k;w++)
	{
		dp[a][b][c][d][e][f] = min(dp[a][b][c][d][e][f],compute(a-arr[w].x[0],b-arr[w].x[1],c-arr[w].x[2],d-arr[w].x[3],e-arr[w].x[4],f-arr[w].x[5]) + arr[w].price);
	}
	return dp[a][b][c][d][e][f];
}

int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		for(int a=0;a<n;a++)
		{
			int x;
			scanf("%d",&x);
			for(int b=0;b<n;b++)
			{
				if(b==a) arr[a].x[b] = 1;
				else arr[a].x[b] = 0;
			}
			arr[a].price = x;
		}
		scanf("%d",&k);
		for(int a=0;a<k;a++)
		{
			int w;
			for(int b=0;b<n;b++)
			{
				scanf("%d",&w);
				arr[n + a].x[b] = w;
			}
			scanf("%d",&w);
			arr[n + a].price = w;
		}
		int c;
		scanf("%d",&c);
		for(int a=0;a<c;a++)
		{
			int arr[15];
			memset(arr,0,sizeof(arr));
			memset(dp,-1,sizeof(dp));
			for(int b=0;b<n;b++)
			{
				scanf("%d",&arr[b]);
			}
			printf("%d\n",compute(arr[0],arr[1],arr[2],arr[3],arr[4],arr[5]) );
		}
	}
}
