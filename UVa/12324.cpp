#include<bits/stdc++.h>
#define INF 1e+9
using namespace std;

typedef struct {
	int t;
	int b;
}Trip;

Trip arr[150];

int dp[150][15000];
int n;

bool cmp(Trip a,Trip b)
{
	if(a.b!=0 && b.b!=0) return a.t < b.t;
	else if(a.b==0 && b.b!=0) return false;
	else if(a.b!=0 && b.b==0) return true;
	else return a.t < b.t;
}

int compute(int nn,int k)
{
	int b = nn;
	if(k<0) return INF;
	if(nn==n) return 0;
	if(dp[nn][k]!=-1) return dp[nn][k];
	if(k==0) return dp[nn][k] = compute(nn+1,k+arr[b].b) + arr[b].t;
	else return dp[nn][k] = min(compute(nn+1,k+arr[b].b - 1) + arr[b].t/2,compute(nn+1,k+arr[b].b) + arr[b].t);
}

int main()
{
	while(scanf("%d",&n),n)
	{
		for(int a=0;a<=n;a++)
			for(int b=0;b<=n*n;b++) dp[a][b] = -1;
		for(int a=0;a<n;a++) scanf("%d %d",&arr[a].t,&arr[a].b);
		//sort(arr,arr+n,cmp);
		printf("%d\n",compute(0,0));
	}
}
