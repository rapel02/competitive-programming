#include<bits/stdc++.h>
using namespace std;

int num[5000005],prime[5000005],ans[5000005];
int k;

void precom()
{
	num[1] = 1;
	for(long long a=2;a<=5000000;a++)
	{
		if(num[a]==0)
		{
			prime[k++] = a;
			for(long long b = a*2 ; b<=5000000;b+=a) num[b] += a;
		}
	}
	for(int a=2;a<=5000000;a++)
	{
		ans[a] = ans[a-1];
		if(num[num[a]]==0) ans[a]++;
	}
}

int main()
{
	precom();
	int a,b;
	while(scanf("%d",&a),a)
	{
		scanf("%d",&b);
		printf("%d\n",ans[b] - ans[a-1]);
	}
}
