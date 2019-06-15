#include<bits/stdc++.h>
using namespace std;

long long ans[15];

int main()
{
	long long n;
	while(1)
	{
		scanf("%lld",&n);
		if(n==0) break;
		int id=0;
		for(int a=0;a<=9;a++)
		{
			if((n-a)%9==0)
			{
				ans[id]=a+(n-a)/9*10;
				id++;
			}
		}
		sort(ans,ans+id);
		for(int a=0;a<id;a++)
		{
			if(a!=0) printf(" ");
			printf("%lld",ans[a]); 
		}
		printf("\n");
	}
}
