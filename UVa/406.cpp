#include<bits/stdc++.h>
using namespace std;

int prime[15000];

int main()
{
	int n,w;
	bool first = true;
	while(scanf("%d %d",&n,&w)!=EOF)
	{
		int k = 1;
		prime[0] = 1;
		for(int a=2;a<=n;a++)
		{
			bool flag = false;
			for(int b=2;b*b<=a;b++)
			{
				if(a%b==0) flag = true;
			}
			if(flag==false)
			{
				prime[k] = a;
				k++;
			}
		}
		printf("%d %d:",n,w);
		if(k%2==1)
		{
			for(int a = max(0,k/2 - w + 1);a<=min(k-1,k/2+w-1);a++)
				printf(" %d",prime[a]);
		}
		else
		{
			for(int a = max(0,k/2 - w);a<=min(k-1,k/2+w-1);a++)
				printf(" %d",prime[a]);
		}
		printf("\n\n");
	}
}
