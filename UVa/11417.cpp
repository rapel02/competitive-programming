#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b)
{
	return (b==0)?a:gcd(b,a%b);
}

int main()
{
	int n;
	while(scanf("%d",&n),n)
	{
		long long tot = 0;
		for(int a=1;a<n;a++)
			for(int b=a+1;b<=n;b++) tot+=gcd(a,b);
		printf("%lld\n",tot);
	}
}
