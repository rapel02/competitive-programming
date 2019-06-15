#include<bits/stdc++.h>
using namespace std;

long long gcd(long long a,long long b)
{
	if(b==0) return a;
	else return gcd(b,a%b);
}

int main()
{
	int t;
	scanf("%d",&t);
	for(int a=1;a<=t;a++)
	{
		long long ans,p;
		scanf("%lld",&p);
		
		printf("Case %d: ",a);
		long long val=p*(p-1);
		long long gc= gcd(val,4);
		if(gc!=4) printf("%lld/%lld",val/gc,4/gc);
		else printf("%lld",val/4);
		printf("\n");
	}
}
