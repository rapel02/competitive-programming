#include<bits/stdc++.h>
using namespace std;

long long ans[50005];
int prime[50005];
int num[50005];
int k = 0;

void cprime()
{
	for(int a=2;a<=50000;a++)
	{
		if(num[a]==0)
		{
			prime[k] = a;
			k++;
			long long b = a;
			while(b*a<=50000)
			{
				num[b*a] = a;
				b++;
			}
		}
	}
}

void compute()
{
	ans[1] = 1;
	for(int a=2;a<=50000;a++)
	{
		int c = a;
		for(int b=0;b<k;b++)
		{
			if(prime[b]>a) break;
			if(a%prime[b]==0)
			{
				c = c/prime[b]*(prime[b]-1);
			}
		}
		ans[a] = ans[a-1] + c;
	}
}

int main()
{
	int n;
	cprime();
	compute();
	while(1)
	{
		scanf("%d",&n);
		if(n==0) break;
		printf("%lld\n",2*ans[n] - 1);
	}
}
