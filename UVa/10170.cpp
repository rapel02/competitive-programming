#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long s,d;
	while(scanf("%lld %lld",&s,&d)!=EOF)
	{
		long long lo=s;
		long long hi=1e+8;
		long long ans=s;
		while(lo<=hi)
		{
			long long mid=(lo+hi)/2;
			long long sum;
			if((s+mid)%2==0) sum=(s+mid)/2*(mid-s+1);
			else sum=(mid-s+1)/2*(s+mid);
			//printf("%lld %lld\n",sum,mid);
			if(sum>=d)
			{
				ans=mid;
				hi=mid-1;
			}
			else lo=mid+1;
		}
		printf("%lld\n",ans);
	}
}
