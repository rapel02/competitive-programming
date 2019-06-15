#include<bits/stdc++.h>
using namespace std;


long long ans1,ans2,tot,gd,x,y;


void ex_eu(long long a,long long b)
{
	if(b==0)
	{
		x=1;
		y=0;
		gd=a;
		return ;
	}
	ex_eu(b,a%b);
	long long x1=y;
	long long y1=x - (a/b)*y;
	x=x1;
	y=y1;
}

int main()
{
	long long a,b;
	while(scanf("%lld %lld",&a,&b)!=EOF)
	{
		ex_eu(a,b);
		tot=1e+13;
		printf("%lld %lld %lld\n",x,y,gd);
	}
}
