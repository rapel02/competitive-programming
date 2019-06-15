#include<bits/stdc++.h>
using namespace std;

int num[35400];
int prime[35400];
int k = 0;

void cek_prime()
{
	for(int a=2;a<=35000;a++)
	{
		if(num[a]==0)
		{
			prime[k] = a;
			k++;
			long long b = a;
			while(b*a<=35000)
			{
				num[b*a] = a;
				b++;
			}
		}
	}
}

int main()
{
	cek_prime();
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		long long in;
		scanf("%lld",&in);
		while(1)
		{
			in++;
			long long d = in;
			int tot = 0;
			int tot2 = 0;
			while(d!=0)
			{
				tot2+=(d%10);
				d/=10;
			}
			d = in;
			int div = 0 ;
			for(int b=0;b<k;b++)
			{
				if(d==1) break;
				while(d%prime[b]==0)
				{
					div++;
					int c = prime[b];
					while(c!=0)
					{
						tot+=(c%10);
						c/=10;
					}
					d/=prime[b];
				}
			}
			if(d!=1)
			{
				if(d==in) continue;
				div++;
				while(d!=0)
				{
					tot+=(d%10);
					d/=10;
				}
			}
			if(div==1) continue;
			if(tot==tot2)
			{
				printf("%lld\n",in);
				break;
			}
		}
	}
}
