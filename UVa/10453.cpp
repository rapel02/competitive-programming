#include<bits/stdc++.h>
using namespace std;

char in[1001];
int len;
int par[1001][1001];
int dp[1001][1001];

int process(int i,int j)
{
	if(i >= j) return 0;
	if(dp[i][j] != -1) return dp[i][j];
	if(in[i] == in[j])
	{
		par[i][j] = 0;
		return dp[i][j] = process(i+1,j-1);
	}
	int v1 = process(i+1,j);
	int v2 = process(i,j-1);
	if(v1 > v2)
	{
		dp[i][j] = v2 + 1;
		par[i][j] = -1;
	}
	else
	{
		dp[i][j] = v1 + 1;
		par[i][j] = 1;
	}
	return dp[i][j];
}

string backtrack(int i,int j)
{
	//printf("%d %d %d\n",i,j,par[i][j]);
	if(i > j) return "";
	if(i == j)
	{
		string ans = "";
		ans += in[i];
		return ans;
	}
	if(par[i][j] == 0)
	{
		return in[i] + backtrack(i+1,j-1) + in[j];
	}
	if(par[i][j] == 1)
	{
		return in[i] + backtrack(i+1,j) + in[i];
	}
	return in[j] + backtrack(i,j-1) + in[j];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	while(cin>>in)
	{
		memset(dp,-1,sizeof(dp));
		len = strlen(in);
		int ans = process(0,len-1);
		cout<<ans<<" "<<backtrack(0,len-1)<<endl;
	}
}
