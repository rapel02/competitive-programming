#include<bits/stdc++.h>
using namespace std;

long long gc,x,y;

void ex_ec(long long a,long long b)
{
	if(b==0)
	{
		gc=a;
		x=1;
		y=0;
		return ;
	}
	ex_ec(b,a%b);
	long long x1=y;
	long long y1=x - (a/b)*y;
	x=x1;
	y=y1;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long xx,k;
		scanf("%lld %lld",&xx,&k);
		long long a=xx/k,b=a;
		if(xx%k!=0) b++;
		ex_ec(a,b);
		printf("%lld %lld\n",xx/gc*x,xx/gc*y);
	}
}
