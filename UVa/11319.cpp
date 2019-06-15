#include<bits/stdc++.h>
#define eps 1e-4
using namespace std;

typedef unsigned long long ULL;

long double arr[10][10];
unsigned long long int ans[10];
unsigned long long int in;

bool test(int a)
{
	unsigned long long int temp=0ULL;
	unsigned long long int c=1ULL;
	for(int b=1;b<=8;b++)
	{
		//printf("%lf ",ans[b]);
		temp=(temp + c*ans[b]);
		c=c*a;
	}
	//printf("\n");
	if(temp==in) return true;
	return false;
} 

void compute()
{
	for(int a=1;a<=7;a++)
	{
		long double temp=arr[a][a];
		if(temp<0.000000000001) continue;
		for(int b=1;b<=8;b++)
			arr[a][b]/=temp;
		for(int b=1;b<=7;b++)
		{
			if(a==b) continue;
			temp = arr[b][a]/arr[a][a];
			for(int c=1;c<=8;c++)
			arr[b][c]=arr[b][c]-arr[a][c]*temp;
		}
	}
	for(int a=1;a<=7;a++)
		ans[a]=arr[a][8];
}

int main()
{
	int t;
	scanf("%d",&t);
	for(int q=0;q<t;q++)
	{
		for(int a=1;a<=7;a++)
		{
			arr[a][1]=1.00;
			for(int b=2;b<=7;b++)
			arr[a][b]=a*arr[a][b-1];
			scanf("%Lf",&arr[a][8]);
		}
		compute();
//		for(int a=1;a<=7;a++) printf("%.0lf ",ans[a]);
		//printf("\n");
		bool ada=true;
		for(int a=8;a<=1500;a++)
		{
			cin>>in;
			if(test(a)==false) ada=false;
		}
		for(int a=1;a<=7;a++)
		{
			if(!(ans[a]>=0&&ans[a]<=1000)) ada=false;
		}
		if(ada==false) printf("This is a smart sequence!");
		else
		{
			for(int b=1;b<=7;b++)
			{
				cout<<ans[b];
				if(b!=7) printf(" ");
			}
		}
		printf("\n");
	}
}
