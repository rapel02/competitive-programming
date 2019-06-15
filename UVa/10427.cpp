#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long n;
	while(scanf("%lld",&n)!=EOF)
	{
		if(n<10) 
		{
			printf("%lld\n",n);
			continue;
		}
		long long tot = 9;
		long long lo = 10;
		long long hi = 99;
		long long k = 2;
		while(tot + (hi - lo + 1) * k <n)
		{
			tot += (hi - lo + 1) * k;
			hi = hi * 10 + 9;
			lo = lo * 10;
			k++;
		}
		long long res = n - tot - 1;
		long long add = res / k;
		long long pans = lo + add;
		long long mv = res %k;
		int w = 0;
		int arr[10];
		while(pans!=0)
		{
			arr[w] = pans%10;
			w++;
			pans/=10;
		}
		printf("%d\n",arr[w-1-mv]);
	}
}
