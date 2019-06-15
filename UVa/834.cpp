#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,r;
	while(scanf("%d %d",&n,&r)!=EOF)
	{
		printf("[%d",n/r);
		n = n % r;
		bool first = true;
		while(n!=0)
		{
			swap(n,r);
			if(first) printf(";%d",n/r);
			else printf(",%d",n/r);
			first = false;
			n = n %r;
		}
		printf("]\n");
	}
}
