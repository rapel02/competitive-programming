#include<bits/stdc++.h>
#define eps 1e-9
using namespace std;

int arr[]={10000,5000,2000,1000,500,200,100,50,20,10,5};
long long dp[35005][15];

long long ans(int a,int b)
{
	if(a==0) return dp[a][b] = 1;
	if(b==11) return dp[a][b] = 0;
	if(dp[a][b]!=-1) return dp[a][b];
	dp[a][b] = 0;
	if(a-arr[b]>=0) dp[a][b] += ans(a-arr[b],b);
	dp[a][b] += ans(a,b+1);
	return dp[a][b];
}

int main()
{
	double in;
	while(scanf("%lf",&in)!=EOF)
	{
		if(in==0.00) break;
		memset(dp,-1,sizeof(dp));
		int w = (in + eps)*100;
		printf("%6.2f%17lld\n",in,ans(w,0));
	}
}
