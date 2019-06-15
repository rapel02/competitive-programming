#include<bits/stdc++.h>
using namespace std;

int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		long long n;
		cin>>n;
		n = abs(n);
		long long lo = 1;
		long long hi = 100000;
		long long ans = 0;
		while(lo <= hi)
		{
			long long mid = (lo + hi) / 2;
			if(mid * (mid + 1) / 2 >= n)
			{
				ans = mid;
				hi = mid-1;
			}
			else lo = mid+1;
		}
		while( ((ans * (ans+1) / 2) - n)%2 != 0) ans++;
		cout<<ans<<"\n";
		if(tc!=0) cout<<"\n";
	}
}
