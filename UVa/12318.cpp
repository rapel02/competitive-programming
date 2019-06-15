#include<bits/stdc++.h>
using namespace std;

long long arr[15];

int main()
{
	long long n,k;
	int m;
	while(1)
	{
		set<long long > s;
		scanf("%lld %d",&n,&m);
		if(n+m==0) break;
		scanf("%lld",&k);
		for(int a=0;a<=k;a++) scanf("%lld",&arr[a]);
		for(int a=0;a<=m;a++)
		{
			long long multi = 1;
			long long rem = 0;
			for(int b=0;b<=k;b++)
			{
				rem = (rem + multi*arr[b])%(n+1);
				multi = (multi*a)%(n+1);
			}
			//cout<<a<<" "<<rem<<endl;
			s.insert(rem);
		}
		printf("%d\n",s.size());
	}
}
