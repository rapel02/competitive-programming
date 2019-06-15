#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long n;
	while(scanf("%lld",&n)!=EOF)
	{
		if(n>13 || (n<0 && n%2==-1)) printf("Overflow!\n");
		else if(n<8 || (n<0 && n%2==0) ) printf("Underflow!\n");
		else
		{
			long long ans = 1;
			for(int a=1;a<=n;a++) ans = ans*a;
		printf("%lld\n",ans);
		}
	}
}
