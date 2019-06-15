#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long l,h;
	while(1)
	{
		scanf("%lld %lld",&l,&h);
		if(l+h==0) break;
		if(l>h) swap(l,h);
		long long ans = 0;
		long long pos = 0;
		for(long long a=l;a<=h;a++)
		{
			long long c = a;
			long long tot = 0;
			do
			{
				tot++;
				if(c%2==1) c = c*3 + 1;
				else c/=2;
			}while(c!=1);
			if(tot>ans)
			{
				ans = tot;
				pos = a;
			}
		}
		printf("Between %lld and %lld, %lld generates the longest sequence of %lld values.\n",l,h,pos,ans);
	}
}
