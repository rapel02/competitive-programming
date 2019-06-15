#include<bits/stdc++.h>
using namespace std;

int dp[55][55];

int arr[55];

int a1,an;

int compute(int val,int pos)
{
	if(val==an) return 1;
	if(dp[val][pos]!=-1) return dp[val][pos];
	int &ans = dp[val][pos];
	ans = 0;
	for(int a=val+1;a<=an;a++)
	{
		if(a % (a - arr[pos])==0)
		{
			arr[pos+1] = a;
			ans += compute(a,pos+1);
		}
	}
	return ans;
}

int main()
{
	while(1)
	{
		scanf("%d %d",&a1,&an);
		if(a1==0 && an==0) break;
		arr[1] = a1;
		memset(dp,-1,sizeof(dp));
		printf("%d %d %d\n",a1,an,compute(a1,1));
	}
}
