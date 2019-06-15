#include<bits/stdc++.h>
using namespace std;

int tot[1005][27];
int trans[1005];
int dp[1006][27];
int len,k;

int compute(int pos,int cha)
{
	if(pos==len/k) return 0;
	if(dp[pos][cha]!=-1) return dp[pos][cha];
	int &ans = dp[pos][cha];
	ans = 100000;
	bool ada = false;
	if(tot[pos][cha]!=0) ada = true;
	for(int a=0;a<26;a++)
	{
		if(tot[pos][a]!=0)
		{
			int rem;
			if(cha==a) rem = compute(pos+1,a) + trans[pos];
			if(cha!=a)
			{
				 rem = compute(pos+1,a) + trans[pos];
				 if(ada==true) rem--;
			}
			ans = min(ans,rem);
		}
	}
	return ans;
}

char in[1500];

int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		scanf("%d",&k);
		scanf("%s",in);
		memset(tot,0,sizeof(tot));
		memset(trans,0,sizeof(trans));
		memset(dp,-1,sizeof(dp));
		len = strlen(in);
		for(int a=0;a<len;a++) tot[a/k][in[a]-'a']++;
		for(int a=0;a<len/k;a++)
		{
			for(int b=0;b<26;b++)
			{
				if(tot[a][b]!=0) trans[a]++;
			}
		}
		int ans = 100000000;
		for(int a=0;a<26;a++)
		{
			if(tot[0][a]!=0) ans = min(ans,compute(1,a) + trans[0]);
		}
		printf("%d\n",ans);
	}
}
