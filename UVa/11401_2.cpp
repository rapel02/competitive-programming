#include<bits/stdc++.h>
using namespace std;

long long ans[1000005];

int main()
{
	ans[3] = 0;
	//ans[4] = 1;
	for(int a=4;a<=1000000;a++)
	{
		ans[a] = ans[a-1];
		long long k = a/2 - 1;
		//printf("%d\n",k);
		ans[a] = ans[a] + (k + 1)*k;
		if(a%2==0) ans[a]-=k;
	}
	int n ;
	while(1)
	{
		scanf("%d",&n);
		if(n<3) break;
		printf("%lld\n",ans[n]);
	}
}
