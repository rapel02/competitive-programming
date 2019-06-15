#include<bits/stdc++.h>
using namespace std;

int num[35000];
int prime[35000];
int k = 0;

void pre()
{
	for(long long a=2;a<=33000;a++)
	{
		if(num[a] == 0)
		{
			prime[k++] = a;
			for(long long b = a*a ;b<=33000;b+=a) num[b] = a;
		}
	}
}

int main()
{
	pre();
	long long n;
	while(cin>>n && n!=0)
	{
		long long tot = n;
		for(int a=0;a<k;a++)
		{
			if(n%prime[a] == 0)
			{
				while(n%prime[a] == 0)
				{
					n/=prime[a];
				}
				tot = tot / prime[a] * (prime[a] - 1);
			}
		}
		if(n!=1) tot = tot / n * (n - 1);
		printf("%lld\n",tot);
	}
}
