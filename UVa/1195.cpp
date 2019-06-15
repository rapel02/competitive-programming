#include<bits/stdc++.h>
using namespace std;


int arr[100005];
int prime[100005];
int k = 0;
int a1 = 0;

void cprime()
{
	for(int a=2;a<=100004;a++)
	{
		if(arr[a]==0)
		{
			prime[k] = a;
			k++;
			long long b = a;
			while(a*b<=100004)
			{
				arr[a*b] = a;
				b++;
			}
		}
	}
}

int m,a,b;

bool check(int m)
{
	a1 = 1;
	for(int wa=0;wa<k;wa++)
	{
		if(prime[wa]*prime[wa]>m) break;
		if(m%prime[wa]==0)
		{
			if(arr[m/prime[wa]] ==0)
			a1 = prime[wa];
		}
	}
	if(m/a1*a <= b*a1) return true;
	return false;
}

int main()
{
	cprime();
	while(1)
	{
		scanf("%d %d %d",&m,&a,&b);
		if(m+a+b==0) break;
		while(1)
		{
			if(check(m)==true)
			{
				printf("%d %d\n",a1,m/a1);
				break;
			}
			m--;
		}
	}
}
