#include<bits/stdc++.h>
#define MOD 1000000009
using namespace std;

struct Matrix{
	long long x[3][3];
};

Matrix Multiply(Matrix aa,Matrix bb)
{
	Matrix temp;
	int a,b,c;
	for(a=0;a<3;a++)
	{
		for(b=0;b<3;b++)
		{
			for(c=0, temp.x[a][b] = 0;c<3;c++)
			temp.x[a][b] = (temp.x[a][b] + ((aa.x[a][c]%MOD)*(bb.x[c][b]%MOD))% MOD ) % MOD;
		}
	}
	return temp;
}

long long fast_mat(long long n)
{
	Matrix ans;
	Matrix c;
	for(int a=0;a<3;a++)
		for(int b=0;b<3;b++)
			ans.x[a][b] = (a==b)?1:0;
	for(int a=0;a<3;a++)
		for(int b=0;b<3;b++)
			c.x[a][b] = (a==b+1 || a==0)?1:0;
	while(n!=0)
	{
		if(n%2==1) ans = Multiply(ans,c);
		c=Multiply(c,c);
		n/=2;
	}
	return	(2*ans.x[0][0]+1*ans.x[0][1])%MOD;
}

long long compute(long long n)
{
	if(n==1) return 0;
	if(n==2) return 1;
	if(n==3) return 2;
	return fast_mat(n-3)%MOD;
}

int main()
{
	long long n;
	while(scanf("%lld",&n)!=EOF)
	{
		if(n==0) break;
		printf("%lld\n",compute(n));
	}
}
