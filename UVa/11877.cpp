#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	while(1)
	{
		scanf("%d",&n);
		if(n==0) break;
		int ans = 0;
		while(n>=2)
		{
			if(n==2) n++;
			ans+=n/3;
			int res = n%3;
			n=n/3;
			n=n+res;
		}
		printf("%d\n",ans);
	}
}
