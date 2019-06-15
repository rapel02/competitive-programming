#include<bits/stdc++.h>
using namespace std;

stack<long long> s;

int main()
{
	long long n;
	while(scanf("%lld",&n)!=EOF)
	{
		if(n<0) break;
		if(n==0) printf("0\n");
		if(n==0) continue;
		while(n!=0)
		{
			s.push(n%3);
			n/=3;
		}
		while(!s.empty())
		{
			printf("%lld",s.top());
			s.pop();
		}
		printf("\n");
	}
}
