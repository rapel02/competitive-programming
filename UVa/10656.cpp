#include<bits/stdc++.h>
using namespace std;

int arr[1500];

int main()
{
	int n;
	bool ff = true;
	while(scanf("%d",&n),n)
	{
		ff = false;
		int ll = -1;
		int rr = -2;
		for(int a=0;a<n;a++)
		{
			scanf("%d",&arr[a]);
			if(arr[a]!=0)
			{
				if(ll==-1) ll = a;
				rr = a;
			}
		}
		for(int b=ll;b<=rr;b++)
		{
			if(arr[b]==0) continue;
			if(b!=ll) printf(" ");
			printf("%d",arr[b]);
		}
		if(ll==-1) printf("0");
		printf("\n");
	}
}
