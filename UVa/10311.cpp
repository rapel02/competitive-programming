#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100000000;

int num[MAXN + 5],prime[MAXN + 5];
int k = 0;
void pre()
{
	num[0] = 1;
	num[1] = 1;
	for(long long a=2;a<=10000;a++)
	{
		if(num[a]==0)
		{
			prime[k++] = a;
			for(long long b=a*a;b<=MAXN;b+=a) num[b] = a;
		}
	}
	for(long long a=10001;a<=MAXN;a++) if(num[a]==0) prime[k++] = a;
}

int main()
{
	pre();
	int n;
	while(cin>>n)
	{
		int p1 = -1,p2 = -1;
		bool err = false;
		if(n==1) err = true;
		else if(n%2==1)
		{
			if(num[n-2]!=0) err = true;
			else p1 = 2,p2 = n-2;
		}
		else if(n==2) err = true;
		else
		{
			for(int a=n/2;a>=0;a--)
			{
				if(a==n-a) continue;
 				if(num[a]==0 && num[n-a]==0)
				{
					p1 = a;
					p2 = n-a;
					break;
				}
			}
			if(p1==-1) err = true;
		}
		if(err==true) printf("%d is not the sum of two primes!\n",n);
		else printf("%d is the sum of %d and %d.\n",n,p1,p2);
	}
}
