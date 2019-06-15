#include<bits/stdc++.h>
using namespace std;

int dp[1005][1005];
string in;

int compute(int i,int j)
{
	if(i >= j) return 0;
	int &ans = dp[i][j];
	if(ans != -1) return ans;
	ans = 1e+9;
	if(in[i] == in[j]) ans = compute(i+1,j-1);
	else ans = min(compute(i+1,j),min(compute(i,j-1),compute(i+1,j-1))) + 1;
	return ans;
}


int main()
{
	int ntc;
	cin>>ntc;
	for(int tc=1;tc<=ntc;tc++)
	{
		memset(dp,-1,sizeof(dp));
		cin>>in;
		printf("Case %d: %d\n",tc,compute(0,in.length() - 1));
	}
}
