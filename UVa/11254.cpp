#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long n;
	while(1)
	{
		scanf("%lld",&n);
		if(n==-1) break;
		long long ll = n;
		long long rr = n;
		long long temp = sqrt(n);
		for(int a=2;a<=n;a++)
		{
			long long sum = a*(a+1)/2;
			if(sum-n>a) break;
			if((n-sum)%a==0)
			{
				if(1+(n-sum)/a<=0) break;
				ll = 1+(n-sum)/a;
				rr = a+(n-sum)/a;
			}
		}
		printf("%lld = %lld + ... + %lld\n",n,ll,rr);
	}
}
