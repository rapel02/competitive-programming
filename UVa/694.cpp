#include<bits/stdc++.h>
using namespace std;

int main()
{
	int k =0;
	while(1)
	{
		k++;
		long long n,lim;
		scanf("%lld %lld",&n,&lim);
		if(n+lim<0) break;
		long long rem = n;
		int tot = 1;
		while(n!=1)
		{
			if(n%2==0) n/=2,tot++;
			else 
			{
				if(3*n+1>lim) break;
				n = 3*n+1;	
				tot++;
			}
		}
		printf("Case %d: A = %lld, limit = %lld, number of terms = %d\n",k,rem,lim,tot);
	}
}
