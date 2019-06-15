#include<bits/stdc++.h>
using namespace std;

int arr[150];
int arr2[150];
int arr3[150];
int dp[150][150];

char in[150000];

int LCS(int a,int b)
{
	if(a==0 || b==0) return 0;
	if(dp[a][b]!=-1) return dp[a][b];
	else if(arr[a]==arr2[b]) return dp[a][b] = 1 + LCS(a-1,b-1);
	else return dp[a][b] = max(LCS(a-1,b),LCS(a,b-1));
}

int main()
{
	int n = 0;
	bool first = true;
	while(scanf("%[^\n]",in)!=EOF)
	{
		getchar();
		int len = strlen(in);
		int k = 1;
		int temp = 0;
		bool sp = false;
		for(int a=0;a<len;a++)
		{
			if(in[a]!=' ') arr2[k] = arr2[k]*10 + (in[a]-'0'),sp=false;
			else if(sp==false) k++,sp = true;
		}
		if(k==1) n = arr[1],first = true;
		else if(first==true)
		{
			for(int a=1;a<=k;a++) arr[arr2[a]] = a+1;
			first = false;
		}
		else
		{
			for(int a=1;a<=k;a++) arr3[arr2[a]] = a+1;
			for(int a=1;a<=k;a++) arr2[a] = arr3[a];
			memset(dp,-1,sizeof(dp));
			printf("%d\n",LCS(k,k));
		}
		for(int a=0;a<=k;a++) arr2[a] = 0;
	}
}
