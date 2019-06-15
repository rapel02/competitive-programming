#include<bits/stdc++.h>
using namespace std;


int main()
{
	long long n;
	while(scanf("%lld",&n)!=EOF)
	{
		long long ans  =0;
		while(n!=0)
		{
			ans++;
			if(n%2!=0&&n!=1) ans++;
			n/=2;
		}
		printf("%lld\n",ans);
	}
}
