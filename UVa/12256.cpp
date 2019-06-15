#include<bits/stdc++.h>
using namespace std;

long long tot[66];

void compute()
{
	tot[1] = tot[2] = tot[3] = 1;
	for(int a=4;a<61;a++)
		tot[a] = tot[a-1] + tot[a-2] + tot[a-3];
}

int main()
{
	int n,a=0;
	compute();
	while(1)
	{
		a++;
		scanf("%d",&n);
		if(n==0) break;
		printf("Case %d: %lld\n",a,tot[n]);
	}
}
