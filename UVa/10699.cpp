#include<bits/stdc++.h>
using namespace std;

int prime[1500000];
int num[1500000];
int k = 0;
void compute()
{
	for(long long a=2;a<=1000000;a++)
	{
		if(num[a]==0)
		{
			prime[k++] = a;
			long long b = a;
			while(b*a<=1000000)
			{
				num[b*a]=a;
				b++;
			}
		}
	}
}

int main()
{
	compute();
	long long n;
	while(scanf("%lld",&n),n)
	{
		int tot = 0;
		for(int a=0;a<k;a++)
		{
			if(n%prime[a]==0) tot++;
		}
		printf("%lld : %d\n",n,tot);
	}
}
