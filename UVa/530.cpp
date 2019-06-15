#include<bits/stdc++.h>
using namespace std;

int num[1500005];
int prime[1500005];
int k = 0 ;

void cprime()
{
	for(long long a=2;a<=1000000;a++)
	{
		if(num[a]==0)
		{
			prime[k++] = a;
			for(long long b=a*a;b<=1000000;b+=a) num[b] = a;
		}
	}
}

long long fast(long long a,long long b)
{
	long long c = a;
	long long ans = 1;
	while(b!=0)
	{
		if(b%2==1) ans = ans*c;
		c=c*c;
		b/=2;
	}
	return ans;
}

long long combin(long long n,long long r)
{
	long long ans = 1;
	for(int a=0;a<k;a++)
	{
		if(n<prime[a]) break;
		long long w = n;
		long long pw = 0;
		while(w!=0)
		{
			pw += w/prime[a];
			w/=prime[a];
		}
		w = r;
		while(w!=0)
		{
			pw -= w/prime[a];
			w/=prime[a];
		}
		w = n-r;
		while(w!=0)
		{
			pw -= w/prime[a];
			w/=prime[a];
		}
		ans = ans * fast(prime[a],pw);
	}
	return ans;
}

int main()
{
	cprime();
	long long n,r;
	while(1)
	{
		n = 0, r = 0;
		long long in,in2;
		scanf("%lld %lld",&in,&in2);
		if(in+in2==0) break;
		else if(in==in2) printf("1\n");
		else if(in2==0) printf("1\n");
		else
		{
			n = in;
			r = in2;
			if(r==1 || n-r==1) printf("%lld\n",n);
			else printf("%lld\n",combin(n,r));
		}
	}
}
