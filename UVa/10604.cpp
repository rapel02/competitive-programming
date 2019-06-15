#include<bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
using namespace std;

const int INF = 2000000000;

int dp[11][11];
pair<int,int> react[7][7];
int res[11][11];
int arr[11];
int n;
int k;

char te[2];

int compute(int l,int r)
{
	if(l==r)
	{
		res[l][r] = react[arr[l]][arr[l]].ff;
		dp[l][r] = react[arr[l]][arr[l]].ss;
		return dp[l][r];
	}
	if(dp[l][r]!=INF) return dp[l][r];
	dp[l][r] = INF - 1;
	for(int a=l;a<r;a++)
	{
		int temp = (compute(l,a) + compute(a+1,r) + react[res[l][a]][res[a+1][r]].ss);
		if(dp[l][r] > temp)
		{
			res[l][r] = react[res[l][a]][res[a+1][r]].ff;
			dp[l][r] = temp;
		}
	}
	return dp[l][r];
}

int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		scanf("%d",&n);
		for(int a=1;a<=n;a++)
			for(int b=1;b<=n;b++)
				scanf("%d %d",&react[a][b].ff,&react[a][b].ss);
		scanf("%d",&k);
		for(int a=0;a<k;a++) scanf("%d",&arr[a]);
		sort(arr,arr+k);
		int ans = INF;
		do
		{
			for(int a=0;a<k;a++) for(int b=0;b<k;b++) dp[a][b] = INF;
			ans = min(ans,compute(0,k-1));
		}while(next_permutation(arr,arr+k));
		printf("%d\n",ans);
		scanf("%s",te);
	}
}
