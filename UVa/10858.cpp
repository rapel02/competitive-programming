#include<bits/stdc++.h>
using namespace std;

int temp;
int input;

int waj[1000];

void counts(int rem,int das,int fak)
{
	//printf("%d %d %d\n",rem,das,fak);
	if(rem==1 && fak>1) temp++;
	else if(rem>1)
	{
		for(int a=das;a<=rem;a++)
		{
			if(rem%a==0)
			{
				counts(rem/a,a,fak+1);
			}
		}
	}
}

void print(int rem,int das,int fak)
{
	//printf("%d %d %d\n",rem,das,fak);
	if(rem==1)
	{
		for(int a=0;a<fak;a++)
		{
			if(a==0) printf("%d",waj[a]);
			else printf(" %d",waj[a]);
		}
		printf("\n");
	}
	else
	for(int a=das;a<=rem;a++)
	{
		if(a==input) break;
		if(rem%a==0)
		{
			waj[fak]=a;
			print(rem/a,a,fak+1);
		}
	}
}

int main()
{
	scanf("%d",&input);
	while(input!=0)
	{
		temp=0;
		counts(input,2,0);
		printf("%d\n",temp);
		if(temp>0)
		{
			print(input,2,0);
		}
		scanf("%d",&input);
	}
	return 0;
}
