#include<bits/stdc++.h>
using namespace std;

map<long long,long long > mmap;

int main()
{
	int tc;
	scanf("%d",&tc);
	for(int a=1;a<=tc;a++)
	{
		mmap.clear();
		long long n;
		scanf("%lld",&n);
		long long b= n;
		while(b!=1&&mmap[b]==0)
		{
			mmap[b]=1;
			long long c = 0;
			long long tp = 0;
			while(b!=0)
			{
				tp = b%10;
				c=c+tp*tp;
				b/=10;
			}
			b = c;
		}
		if(b==1) printf("Case #%d: %lld is a Happy number.\n",a,n);
		else printf("Case #%d: %lld is an Unhappy number.\n",a,n);
	}
}
