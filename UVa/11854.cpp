#include<bits/stdc++.h>
using namespace std;

int main()
{
	while(1)
	{
		long long a,b,c;
		scanf("%lld %lld %lld",&a,&b,&c);
		if(a+b+c==0) break;
		if(a*a + b*b == c*c) printf("right");
		else if(a*a + c*c == b*b) printf("right");
		else if(b*b + c*c == a*a) printf("right");
		else printf("wrong");
		printf("\n");
	}
}
