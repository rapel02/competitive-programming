#include<bits/stdc++.h>
using namespace std;

int prime[35000];
int num[35000];
int k = 0 ;

void cprime()
{
	num[1] = 1;
	num[0] = 1;
	for(int a=2;a<=33000;a++)
	{
		if(num[a]==0)
		{
			prime[k++]  = a;
			for(int b = a*a ;b<=33000;b+=a) num[b] = a;
		}
	}
}

int main()
{
	cprime();
	int n;
	while(scanf("%d",&n),n)
	{
		int tot = 0;
		for(int a=0;prime[a]<=n/2&&a<k;a++)
		{
			if( num[n - prime[a]] ==0) tot++;
		}
		printf("%d\n",tot);
	}
}
