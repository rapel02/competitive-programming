#include<bits/stdc++.h>
using namespace std;

long long arr[100];
long long LC[660000];

long long GCD(long long a,long long b)
{
	return (b==0)?a:GCD(b,a%b);
}

int main()
{
	int t,c;
	while(1)
	{
		scanf("%d %d",&t,&c);
		if(t+c==0) break;
		for(int a=0;a<t;a++) 
		{
			scanf("%lld",&arr[a]);
		}
		int k = 0;
		for(int a=0;a<t;a++)
		{
			for(int b=a+1;b<t;b++)
			{
				for(int c=b+1;c<t;c++)
				{
					for(int d=c+1;d<t;d++)
					{
						long long t1 = arr[a] / GCD(arr[a],arr[b]) *arr[b];
						t1 = t1 / GCD(t1,arr[c]) * arr[c];
						t1 = t1/ GCD(t1,arr[d]) * arr[d];
						LC[k++] = t1;
					}
				}
			}
		}
		for(int a=0;a<c;a++)
		{
			long long w;
			scanf("%lld",&w);
			long long lo = 0;
			long long hi = 100000000000;
			for(int b=0;b<k;b++)
			{
				long long ans = w/LC[b];
				lo = max(lo,ans*LC[b]);
				if(w%LC[b]!=0) ans++;
				hi = min(hi,ans*LC[b]);
			}
			printf("%lld %lld\n",lo,hi);
		}
	}
}
