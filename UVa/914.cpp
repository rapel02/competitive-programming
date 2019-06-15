#include<bits/stdc++.h>
using namespace std;

int num[1000005],prime[1000005],k = 0;
int tot[115];


void precom()
{
	for(long long a=2;a<=1000000;a++)
	{
		if(num[a]==0)
		{
			prime[k++] = a;
			for(long long b=a*a;b<=1000000;b+=a) num[b] = a;
		}
	}
	prime[k++] = 1000001;
}

int main()
{
	precom();
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		int l,r;
		scanf("%d %d",&l,&r);
		int c = 0;
		while(prime[c] < l) c++;
		bool first = false;
		if(prime[c+1] > r) first = true;
		c = c+1;
		memset(tot,0,sizeof(tot));
		while(prime[c] <=r)
		{
			tot[prime[c]-prime[c-1]]++;
			c++;
		}
		int maxx = 0, rem = 0;
		bool issame = false;
		for(int a=1;a<115;a++)
		{
			if(tot[a]==maxx) issame = true;
			if(tot[a] > maxx)
			{
				maxx = tot[a];
				issame = false;
				rem = a;
			}
		}
		if(issame ==true || first==true) printf("No jumping champion\n");
		else printf("The jumping champion is %d\n",rem);
	}
}
