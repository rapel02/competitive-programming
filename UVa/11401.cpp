#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long n;
	while(1)
	{
		scanf("%lld",&n);
		if(n<3) break;
		if(n<=3) printf("0\n");
		else
		{
			n-=2;
			long long ans;
			long long w= n;
			n/=2;
			if(w%2==0) ans = 1+ (n-1)*6 +(n-1)*(n-2)*9/2 +(n-1)*(n-2)*(n-3)*4/6;
			else ans = 3 + (n-1)*10 +(n-1)*(n-2)*11/2 +(n-1)*(n-2)*(n-3)*4/6;
			printf("%lld\n",ans);	
		}
	}
}
