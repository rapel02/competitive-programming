#include<bits/stdc++.h>
using namespace std;

long long dp[35][35][2][35];

int D,G;

long long compute(int m,int g,int p,int v)
{
	if(m<0 || g<0) return 0;
	if(v>G && m>0 && p==1 || v>G && g>0 && p==0) return 0;
	if(m==0 && g==0)
	{
		if(p==0) return 0;
		return 1;
	}
	if(dp[m][g][p][v]!=-1) return dp[m][g][p][v];
	dp[m][g][p][v] = 0;
	long long &res = dp[m][g][p][v];
	if(p==0) res = compute(m-1,g,0,v+1) + compute(m,g-1,1,1);
	if(p==1) res = compute(m-1,g,0,1) + compute(m,g-1,1,v+1);
	return res;
}
//
//long long dp[70][35][35][35];
//
//long long compute2(int pos,int res,int put,int pput)
//{
//	if(pos==2*D)
//	{
//		if(res==0) return 1;
//		return 0;
//	}
//	if(pput>G+1) return 0;
//	if(res<0) return 0;
//	if(put>G+1) return 0;
//	if(dp[pos][res][put][pput]!=-1) return dp[pos][res][put][pput];
//	long long &temp = dp[pos][res][put][pput];
//	temp = compute2(pos+1,res-1,1,pput+1) + compute2(pos+1,res,put+1,1);
//	return temp; 
//}

int main()
{
	int tc = 0;
	while(scanf("%d %d",&D,&G)!=EOF)
	{
		if(D+G<0) break;
		tc++;
		memset(dp,-1,sizeof(dp));
		printf("Case %d: %lld\n",tc,compute(D-1,D,0,1)*2);
		//printf("Case %d: %lld\n",tc,2*compute2(2,D-1,1,2));
	}
}
