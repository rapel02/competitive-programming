#include<bits/stdc++.h>
using namespace std;

stack<int> s;

int main()
{
	long long n;
	while(1)
	{
		scanf("%lld",&n);
		if(n==0) break;
		int tot = 0;
		while(n!=0)
		{
			s.push(n%2);
			if(n%2==1) tot++;
			n/=2;
		}
		printf("The parity of ");
		while(!s.empty())
		{
			printf("%d",s.top());
			s.pop();
		}
		printf(" is %d (mod 2).\n",tot);
	}
}
