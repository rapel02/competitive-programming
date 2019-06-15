#include<bits/stdc++.h>
using namespace std;

int tot[1500];

void pre()
{
	for(int a=1;a<=1000;a++)
	{
		for(int b=a;b<=1000;b+=a) tot[b] += a;
	}
}

int main()
{
	pre();
	int tc = 0;
	int n;
	while(cin>>n && n!=0)
	{
		int ans = -1;
		for(int a=1;a<=1000;a++) if(tot[a] == n) ans = a;
		printf("Case %d: %d\n",++tc,ans);
	}
}
