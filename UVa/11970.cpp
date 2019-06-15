#include<bits/stdc++.h>
using namespace std;

int main()
{
	int ntc;
	scanf("%d",&ntc);
	for(int tc=1;tc<=ntc;tc++)
	{
		set<long long > s;
		long long n;
		scanf("%lld",&n);
		long long k = 1;
		for(k = 1;k*k<n;k++)
		{
			long long X = n - k*k;
			if(X%k == 0) s.insert(X);
		}
		printf("Case %d:",tc);
		for(set<long long>::iterator it = s.begin();it!=s.end();it++)
		{
			cout<<" "<<*it;
		}
		printf("\n");
	}
}
