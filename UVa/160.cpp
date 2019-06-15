#include<bits/stdc++.h>
using namespace std;

int num[150];
int prime[150];
int k =0;
void compute()
{
	for(int a=2;a<=100;a++)
	{
		if(num[a]==0)
		{
			prime[k] = a;
			k++;
			int b = a;
			while(b*a<=100)
			{
				num[b*a] = a;
				b++;
			}
		}
	}
}

int main()
{
	int n;
	compute();
	while(1)
	{
		scanf("%d",&n);
		if(n==0) break;
		printf("%3d! =",n);
		int ww = 0;
		for(int a=0;a<k;a++)
		{
			if(n<prime[a]) break;
			int tot = 0;
			int c = n;
			while(c!=0)
			{
				tot +=c/prime[a];
				c/=prime[a];
			}
			printf("%3d",tot);
			ww++;
			if(n<prime[a+1]) break;
			if(ww==15)
			{
				printf("\n");
				ww = 0;
				printf("      ");
			}
		}
		printf("\n");
	}
}
