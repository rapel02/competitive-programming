#include<bits/stdc++.h>
using namespace std;


int dp[1000005];

void compute()
{
	dp[0] = 1;
	for(int a=1;a<=1000000;a++)
	{
		double cq = a;
		dp[a] = dp[int(cq-sqrt(cq))] + dp[int (log(cq))] + dp[int(cq*sin(cq)*sin(cq))];
		dp[a]%=1000000;
	}
}

int main()
{
	compute();
	int n;
	while(1)
	{
		scanf("%d",&n);
		if(n<0) break;
		printf("%d\n",dp[n]);
	}
}
