#include<bits/stdc++.h>
using namespace std;

int dp[1500][1500]; // prev, val state: pick: res
int arr[1500];
int n;

bool ff;

bool backtrack(int pos,int val,int k)
{
	if(k==n && val%n==0)
	{
		printf("Yes\n");
		return true;
	}
	if(pos==2*n-1) return false;
	if(k==n) return false;
	if(backtrack(pos+1,val + arr[pos],k+1))
	{
		if(!ff) printf(" ");
		ff = false;
		printf("%d",arr[pos]);
		return true;
	}
	if(backtrack(pos+1,val,k)) return true;
	return false;
}

int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0) break;
		ff = true;
		for(int a=0;a<2*n - 1;a++) scanf("%d",&arr[a]);
		if(!backtrack(0,0,0)) printf("No");
		printf("\n");
	}
}
