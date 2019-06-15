#include<bits/stdc++.h>
using namespace std;

int arr[20005];
int n=1,m=1;

bool cmp(int a,int b)
{
	if((a%m)%m<(b%m )%m) return true;
	else if((a%m)%m==(b%m)%m)
	{
		if((a%2 + 2)%2!=(b%2 + 2)%2) return (a%2 + 2)%2 > (b%2 + 2) % 2;
		if((a%2 + 2 )%2==(b%2 + 2)%2 && (a%2 + 2)%2==1) return a>b;
		else if((a%2 + 2)%2==(b%2 + 2)%2 && (a%2+ 2)%2==0) return a<b;
		return false;
	}
	return false;
}

int main()
{
	while(1)
	{
		if(n==0 && m==0) break;
		scanf("%d %d",&n,&m);
		for(int a=0;a<n;a++) scanf("%d",&arr[a]);
		sort(arr,arr+n,cmp);
		printf("%d %d\n",n,m);
		for(int a=0;a<n;a++) printf("%d\n",arr[a]);
	}
}
