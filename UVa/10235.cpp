#include<bits/stdc++.h>
using namespace std;

int num[1500000];

void cprime()
{
	num[1] = 1;
	for(long long a = 2;a<=1000000;a++)
	{
		if(num[a]==0)
		{
			for(long long b = a*a;b<=1000000;b+=a) num[b] = a;
		}
	}
}

int main()
{
	cprime();
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int rev = 0;
		int k = n;
		while(k!=0)
		{
			rev = rev*10 + k%10;
			k/=10;
		}
		if(num[rev]==0 && num[n]==0 && rev!=n) printf("%d is emirp.\n",n);
		else if(num[n]==0) printf("%d is prime.\n",n);
		else printf("%d is not prime.\n",n);
	}
}
