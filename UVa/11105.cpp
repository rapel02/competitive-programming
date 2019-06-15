#include<bits/stdc++.h>
using namespace std;

int num[1000001];
int prime[1000001];
long long bil[1000001];
int k = 0;

set<long long> s;

void compute()
{
	for(int a=5;a<=200001;a+=4)
	{
		if(num[a]==0)
		{
			prime[k] = a;
			k++;
			long long b = a;
			while(b*a<=200001)
			{
				//if(b*a%4!=1) continue;
				num[b*a] = 1;
				b+=4;
			}
		}
	}
}

int main()
{
	compute();
	int tot = 0;
	sort(prime,prime+k);
	for(int a=0;a<k;a++)
	{
		for(int b=a;b<k;b++)
		{
			long long w = prime[a];
			w*=prime[b];
			//if(w%4!=1) continue;
			if(w>1000001) break;
			int sz = s.size();
			s.insert(w);
			if(s.size()!=sz)
			{
				bil[tot] = w;
				tot++;
			}
		}
	}
	sort(bil,bil+tot);
	while(1)
	{
		int n;
		scanf("%d",&n);
		if(n==0) break;
		int lo = 0;
		int hi = tot-1;
		int ans = 0;
		while(lo<=hi)
		{
			int mid = (lo+hi)/2;
			if(bil[mid]<=n)
			{
				ans = mid+1;
				lo = mid+1;
			}
			else hi = mid-1;
		}
		printf("%d %d\n",n,ans);
	}
}
