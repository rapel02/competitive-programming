#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	long long n,r;
	while(cin>>n>>r)
	{
		double to = 0;
		double bo = 0;
		for(long long a=n;a>n-r;a--) to += log10(a);
		for(long long b=1;b<=r;b++) bo += log10(b);
		double ans = to - bo;
		int an = floor(ans) + 1;
		cout<<an<<"\n";
	}
}
