#include<bits/stdc++.h>
using namespace std;

long long Combin(long long a)
{
	return a*(a-1)*(a-2)/6;
}

int main()
{
	long long m,n;
	int tc = 0;
	while(cin>>m>>n)
	{
		tc++;
		if(m+n==0) break;
		m++;
		n++;
		long long M = m*n;
		long long t1 = 0;
		long long t2 = 0;
		while(M!=0)
		{
			M -= m;
			t1 += M;
			t2 += M*(M-1)/2;
		}
		printf("Case %d: %lld\n",tc,t1*m*(m-1)/2 + t2*m);
	}
}
