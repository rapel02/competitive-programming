#include<bits/stdc++.h>
using namespace std;

long long di[1000005];
int ans[1000005],rem[1000005];

void precom()
{
	for(int a=1;a<=1000000;a++)
		for(int b=a;b<=1000000;b+=a) di[b]++;
	for(int a=1;a<=1000000;a++)
	{
		if(rem[a-1] <= di[a]) rem[a] = di[a], ans[a] = a;
		else rem[a] = rem[a-1],ans[a] = ans[a-1];
	}
}

int main()
{
	precom();
	int n;
	scanf("%d",&n);
	while(n--)
	{
		int w;
		scanf("%d",&w);
		printf("%d\n",ans[w]);
	}
}
