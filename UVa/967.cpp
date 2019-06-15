#include<bits/stdc++.h>
using namespace std;

int k = 0;
int num[1500000];
int prime[1500000];
int ans[1500000];

int numdig(int a)
{
	int k = 0;
	while(a!=0) a/=10,k++;
	return k;
}

void cprime()
{
	for(long long a=2;a<=1000000;a++)
	{
		if(num[a]==0)
		{
			prime[k++] = a;
			for(long long b = a*a ; b<=1000000;b+=a) num[b] = a;
		}
	}
	ans[100] = 0;
	for(int a=101;a<1000000;a++)
	{
		ans[a] = ans[a-1];
		if(num[a]==0)
		{
			int dig = numdig(a);
			int div = 1;
			for(int b=1;b<dig;b++) div*=10;
			bool prr = true;
			int c = a;
			for(int b=1;b<=dig;b++)
			{
				c = c/div + (c%div)*10;
				if(num[c]!=0) prr = false;
			}
			if(prr==true) ans[a]++;
		}
	}
}

int main()
{
	cprime();
	while(1)
	{
		int l,r;
		scanf("%d",&l);
		if(l==-1) break;
		scanf("%d",&r);
		int tot = ans[r] - ans[l-1];
		if(tot==0) printf("No Circular Primes.\n");
		else if(tot==1) printf("1 Circular Prime.\n");
		else printf("%d Circular Primes.\n",tot);
	}
}
