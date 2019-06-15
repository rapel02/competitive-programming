#include<bits/stdc++.h>
using namespace std;

const long long INF = 1e+12;

long long pow(long long a,long long b)
{
	long long ans = 1;
	while(b)
	{
		if(a >= INF || ans >= INF || ans < 0 || a < 0) return INF;
		if(b&1) ans=(ans*a);
		b/=2;
		a*=a;
	}
	return ans;
}

int main()
{
	long long n;
	while(cin>>n && n!=0)
	{
		int ans = 1;
		for(int a=2;a<=35;a++)
		{
			if(a==2)
			{
				long long tp = sqrt(n);
				if(tp * tp == n) ans = 2;
			}
			else
			{
				long long no = 1;
				while(pow(no,a) < abs(n)) no++;
				if(pow(no,a) == n) ans = a;
				if(pow(-no,a) == n) ans = a; 
			}
		}
		if(n == 1) ans = 0;
		printf("%d\n",ans);
	}
}
