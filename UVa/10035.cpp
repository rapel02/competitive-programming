#include<bits/stdc++.h>
using namespace std;

int main()
{
	int tot;
	long long n,m;
	while(1)
	{
		tot = 0;
		scanf("%lld %lld",&n,&m);
		if(n+m==0) break;
		int res = 0;
		while(n!=0 || m!=0)
		{
			if(n%10+m%10+res>9)
			{
				res = (n%10 + m%10 +res)/10;
				tot++;
			}
			else res = 0;
			n/=10;
			m/=10;
		}
		if(tot==0) printf("No");
		else printf("%d",tot);
		printf(" carry operation%s.\n",(tot>1)?"s":"");
	}
}
