#include<bits/stdc++.h>
using namespace std;

stack<int> s;

int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		long long in;
		scanf("%lld",&in);
		long long tp = in;
		int a1 = 0,a2 = 0;
		while(tp!=0)
		{
			if(tp%2==1) a1++;
			tp/=2;
		}
		tp = in;
		long long ans = 0;
		while(tp!=0)
		{
			s.push(tp%10);
			tp/=10;
		}
		while(!s.empty())
		{
			ans = ans*16 + s.top();
			s.pop();
		}
		while(ans!=0)
		{
			if(ans%2==1) a2++;
			ans/=2;
		}
		printf("%d %d\n",a1,a2);
	}
}
