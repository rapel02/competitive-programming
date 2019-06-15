#include<bits/stdc++.h>
using namespace std;

long long mod = 0;
long long aa,bb,n,m;

struct Matrix{
	int x[2][2];
};

Matrix maxmul(Matrix a,Matrix b)
{
	Matrix c;
	for(int aa=0;aa<2;aa++)
	{
		for(int bb=0;bb<2;bb++)
		{
			int cc;
			for(cc = 0, c.x[aa][bb] = 0 ;cc<2;cc++)
			{
				c.x[aa][bb] = (c.x[aa][bb] + a.x[aa][cc] * b.x[cc][bb])%mod ;
			}
		}
	}
	return c;
}

long long compute(long long n)
{
	if(n==-1) return aa;
	Matrix c,ans;
	for(int a=0;a<2;a++)
		for(int b=0;b<2;b++)
			if(a+b!=2) c.x[a][b] = 1;
			else c.x[a][b] = 0;
	for(int a=0;a<2;a++)
		for(int b=0;b<2;b++)
			if(a==b) ans.x[a][b] = 1;
			else ans.x[a][b] = 0;
	while(n!=0)
	{
		if(n%2==1) ans = maxmul(ans,c);
		c = maxmul(c,c);
		n/=2;
	}
	return (ans.x[0][0] * bb + ans.x[0][1]*aa)%mod;
}

int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		scanf("%lld %lld %lld %lld",&aa,&bb,&n,&m);
		mod = 1;
		for(int a=1;a<=m;a++)
			mod = mod*10;
		printf("%lld\n",compute(n-1));
	}
}
