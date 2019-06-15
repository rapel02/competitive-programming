#include<bits/stdc++.h>
using namespace std;

long long tot[65000];

void compute()
{
	for(int a=1;a<=60000;a++)
	{
		for(int b=a+a;b<=60000;b+=a) tot[b]+=a;
	}
}

int main()
{
	compute();
	int n;
	printf("PERFECTION OUTPUT\n");
	while(1)
	{
		scanf("%d",&n);
		if(n==0) break;
		printf("%5d  ",n);
		if(n==tot[n]) printf("PERFECT\n");
		else if(n>tot[n]) printf("DEFICIENT\n");
		else printf("ABUNDANT\n");
	}
	printf("END OF OUTPUT\n");
}
