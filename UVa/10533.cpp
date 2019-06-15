#include<bits/stdc++.h>
using namespace std;

int num[1000005],ans[1000005];

void compute()
{
	num[1] = 1;
	num[0] = 1;
	for(long long a=2;a<=1000000;a++)
		if(num[a]==0) for(long long b=a*a;b<=1000000;b+=a) num[b] = a;
	ans[0] = 0;
	for(int a=2;a<=1000000;a++)
	{
		ans[a] = ans[a-1];
		if(num[a]==0)
		{
			int c = a;
			int tot = 0;
			while(c!=0) tot+=c%10,c/=10;
			if(num[tot]==0) ans[a]++;
		}
	}
}

int main()
{
	compute();
	int n;
	scanf("%d",&n);
	while(n--)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		printf("%d\n",ans[b]-ans[a-1]);
	}
}
