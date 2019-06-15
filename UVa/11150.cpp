#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int tot = n;
		while(n>=3)
		{
			tot += n/3;
			n=n/3 + n%3;
		}
		if(n==2) tot++;
		printf("%d\n",tot);
	}
}
