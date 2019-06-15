#include<bits/stdc++.h>
using namespace std;

int main()
{
	int test,price;
	scanf("%d",&test);
	for(int a=1;a<=test;a++)
	{
		int tax=0;
		scanf("%d",&price);
		int temp=price;
		price-=180000;
		temp=price;
		if(price>0)
		{
			if(price>=300000)
			{
				tax+=300000*10/100;
			}
			else
			{
				price*=10;
				if(price%100!=0) tax+=price/100+1;
				else tax+=price/100;
			}
			price=temp;
			price-=300000;
		}
		//printf("%d %d\n",tax,price);
		temp=price;
		if(price>0)
		{
			if(price>=400000)
			{
				tax+=400000*15/100;
			}
			else
			{
				price*=15;
				if(price%100!=0) tax+=price/100+1;
				else tax+=price/100;
			}
			price=temp;
			price=price-400000;
		}
		//printf("%d %d\n",tax,price);
		temp=price;
		if(price>0)
		{
			if(price>=300000)
			{
				tax+=300000*20/100;
			}
			else
			{
				price*=20;
				if(price%100!=0) tax+=price/100+1;
				else tax+=price/100;
			}
			price=temp;
			price-=300000;
		}
		//printf("%d\n",tax);
		if(price>0)
		{
			if(price%4!=0)
				tax+=price/4+1;
			else tax+=price/4;
		}
		//printf("%d\n",tax);
		if(tax!=0 && tax<2000) tax=2000;
		printf("Case %d: %d\n",a,tax);
	}
}
