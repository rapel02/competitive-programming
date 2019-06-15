#include<bits/stdc++.h>
using namespace std;


long long num[100000];

int k;

int pre()
{
	num[0]=1;
	int a=0;
	long long ang=1LL<<31;
	while(num[a]<ang)
	{
		a++;
		num[a]=num[a-1]*2;
	}
	a++;
	k=a;
	for(int b=0;b<a;b++)
	{
		long long now=num[b];
		while(now<ang)
		{
			num[k]=now*3;
			now=num[k];
			k++;
		}
	}
	sort(num,num+k);
}
long long binser(long long tar)
{
	int hi=k;
	int lo=0;
	long long ans;
	while(lo<=hi)
	{
		int mid=(lo+hi)/2;
		if(num[mid]>=tar)
		{
			ans=num[mid];
			hi=mid-1;
		}
		else lo=mid+1;
	}
	return ans;
}
int main()
{
	pre();
	long long in;
	scanf("%lld",&in);
	while(in!=0)
	{
		printf("%lld\n",binser(in));
		scanf("%lld",&in);
	}
	
}
