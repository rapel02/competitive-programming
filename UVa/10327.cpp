#include<bits/stdc++.h>
using namespace std;

long long arr[1005];

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		long long tot = 0;
		for(int a=0;a<n;a++) scanf("%lld",&arr[a]);
		for(int a=0;a<n;a++)
			for(int b=a+1;b<n;b++)
				if(arr[a]>arr[b]) tot++;
		printf("Minimum exchange operations : %lld\n",tot);
	}
}
