#include<bits/stdc++.h>
using namespace std;

long long fast(long long a,long long b,long long MOD)
{
	long long ans = 1;
	a%=MOD;
	while(b!=0)
	{
		if(b%2==1) ans = (ans * a)%MOD;
		a = (a*a)%MOD;
		b/=2;
	}
	return ans;
}

int main()
{
	int ntc;
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>ntc;
	for(int tc=1;tc<=ntc;tc++)
	{
		int n;
		long long k,mod;
		cin>>n>>k>>mod;
		long long tot = 0;
		for(int a=0;a<n;a++)
		{
			long long num;
			cin>>num;
			tot = (tot + num) % mod;
		}
		long long ans = tot * fast(n,k-1LL,mod) % mod * k %mod;
		cout<<"Case "<<tc<<": "<<ans<<endl;
	}
}
