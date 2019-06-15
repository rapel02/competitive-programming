#include<bits/stdc++.h>
using namespace std;

long long arr[20];
long long multi;

long long gcd(long long a,long long b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}

long long kpk(long long a,long long b)
{
	return a/gcd(a,b)*b;
}

long long cek(int bit)
{
	multi = 1;
	int k = 0;
	int res = 0;
	while(bit!=0)
	{
		if(bit%2==1)
		{
			res++;
			multi=kpk(multi,arr[k]);
		}
		k++;
		bit/=2;
	}
	return res;
}


int main()
{
	long long n;
	int m;
	while(scanf("%lld %d",&n,&m)!=EOF)
	{
		for(int a=0;a<m;a++)
			scanf("%lld",&arr[a]);
		long long tot = 0;
		for(int a=1;a<(1<<m);a++)
		{
			if(cek(a)%2==1) tot = tot + n / multi;
			else tot = tot - n / multi;
		}
		printf("%lld\n",n-tot);
	}
}
