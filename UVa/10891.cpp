#include<bits/stdc++.h>
#define INF 1e+9
using namespace std;

int dp[150][150];
int pref[150];
int arr[150];

int prefsum(int l,int r)
{
	return pref[r] - pref[l-1];
}

int compute(int l,int r)
{
	if(l>r) return 0;
	if(dp[l][r]!=-INF) return dp[l][r];
	for(int a=l;a<=r;a++)
		dp[l][r] = max(dp[l][r],prefsum(l,a) - compute(a+1,r));
	for(int a=r;a>=l;a--)
		dp[l][r] = max(dp[l][r],prefsum(a,r) - compute(l,a-1));
	return dp[l][r];
}

int main()
{
	int n;
	while(scanf("%d",&n),n)
	{
		for(int a=1;a<=n;a++)
		{
			scanf("%d",&arr[a]);
			pref[a] = pref[a-1] + arr[a];
		} 
			for(int b=0;b<150;b++)
				for(int c=0;c<150;c++) dp[b][c] = -INF;
		printf("%d\n",compute(1,n));
	}
}
