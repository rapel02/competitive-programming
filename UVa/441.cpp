#include<bits/stdc++.h>
using namespace std;

int num[100];

int main()
{
	int test;
	scanf("%d",&test);
	while(test!=0)
	{
		for(int a=0;a<test;a++)
			scanf("%d",&num[a]);
		sort(num,num+test);
		for(int a=0;a<test;a++)
		{
			for(int b=a+1;b<test;b++)
			{
				for(int c=b+1;c<test;c++)
				{
					for(int d=c+1;d<test;d++)
					{
						for(int e=d+1;e<test;e++)
						{
							for(int f=e+1;f<test;f++)
								printf("%d %d %d %d %d %d\n",num[a],num[b],num[c],num[d],num[e],num[f]);
						}
					}
				}
			}
		}
		scanf("%d",&test);
		if(test!=0)
			printf("\n");
	}
}
