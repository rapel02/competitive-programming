#include<bits/stdc++.h>
using namespace std;

int tot[150000];

bool isPrime(long long b)
{
	for(long long a=2;a*a<=b;a++) if(b%a==0) return false;
	return true;
}

void compute()
{
	tot[0] = 1;
	for(long long a=1;a<=20000;a++)
	{
		tot[a] = tot[a-1];
		if(isPrime(a*a + a + 41)) tot[a]++;
	}
}

int main()
{
	compute();
	int a,b;
	while(scanf("%d %d",&a,&b)!=EOF)
	{
		if(a>b) swap(a,b);
		int ans = 0;
		if(a==0) ans = tot[b];
		else if(a!=0) ans = tot[b] - tot[a-1];
		printf("%.2lf\n",((double)(1.0*(ans)/(b-a+1))) * 100.00 +1e-6);
	}
}
