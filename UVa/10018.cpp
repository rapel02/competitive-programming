#include<bits/stdc++.h>
using namespace std;

int main()
{
	int test;
	long long num,rev,add,temp,comp,step;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%lld",&num);
		step=0;
		comp=0;
		do
		{
			temp=num;
			comp=0;
			while(temp!=0)
			{
				comp=comp*10+temp%10;
				temp/=10;
			}
			if(comp==num && step!=0)
			{;
			}
			else
			{
				step++;
				num=num+comp;
			}
		}while(num!=comp);
		printf("%lld %lld\n",step,num);
	}
}
