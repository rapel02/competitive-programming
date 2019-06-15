#include<bits/stdc++.h>
using namespace std;

long long arr[2000][2000];

void precom()
{
	for(int a=1;a<2000;a++)
	{
		for(int b=0;b<=a;b++)
		{
			if(b==0 || b==a) arr[a][b] = 1;
			else arr[a][b] = arr[a-1][b] + arr[a-1][b-1];
		}
	}
}

long long Combin(long long n,long long r)
{
	if(r==n || r==0) return 1;
	if(r==1 || r==n-1) return n;
	if(r==2 || r==n-2) return n*(n-1)/2;
	if(r==3 || r==n-3) return n*(n-1)*(n-2)/6;
	return arr[n][r];
}

int main()
{
	precom();
	int n,m,t;
	while(cin>>n)
	{
		cin>>m;
		long long ans = 1;
		for(int a=0;a<m;a++)
		{
			cin>>t;
			ans *= Combin(n,t);
			n-=t;
		}
		printf("%lld\n",ans);
	}
}
