#include<bits/stdc++.h>
using namespace std;

struct pairW{
	double x;
	double y;
}p[1000005];

bool cmp(pairW a,pairW b)
{
	double a1 = a.x/a.y;
	double a2 = b.x/b.y;
	return a1<a2;
}

int gcd(int a,int b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}

int main()
{
	long long n,k;
	while(scanf("%lld %lld",&n,&k)!=EOF)
	{
		int kw = 0;
		for(int a=1;a<=n;a++)
		{
			for(int b=a;b<=n;b++)
			{
				if(gcd(a,b)!=1) continue;
				p[kw].x = a;
				p[kw].y = b;
				kw++;
			}
		}
		sort(p,p+kw,cmp);
		printf("%.0lf/%.0lf\n",p[k-1].x,p[k-1].y);
	}
}

