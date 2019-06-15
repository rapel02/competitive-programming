#include<bits/stdc++.h>
using namespace std;

int ans[10005];

void precompute()
{
	ans[0] = 1;
	ans[1] = 1;
	for(int a=2;a<=10000;a++)
	{
		int w = a;
		ans[a] = (ans[a-1] * w);
		while(ans[a]%10==0) ans[a]/=10;
		ans[a]%=100000;
	}
}

int main()
{
	precompute();
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		printf("%5d -> %d\n",n,ans[n]%10);
	}
}
