#include<bits/stdc++.h>
using namespace std;

int num[1000005],prime[1000005],k = 0;
int ans[1000005];

void precom()
{
	for(long long a=2;a<=1000000;a++)
	{
		if(num[a]==0)
		{
			for(long long b=a*a;b<=1000000;b+=a) num[b] = a;
		}
	}
	ans[1] = 0;
	for(long long a=2;a<=1000000;a++)
	{
		ans[a] = ans[a-1];
		int c = a;
		int tot = 1;
		while(num[c]!=0)
		{
			c /= num[c];
			tot++;
		}
		ans[a] += tot;
	}
}

int main()
{
	precom();
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		printf("%d\n",ans[n]);
	}
}
