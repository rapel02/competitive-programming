#include<bits/stdc++.h>
using namespace std;


long long arr[1500];
int tot[15];
const long long INF = 1e+9;

int main()
{
	int n;
	while(cin>>n && n!=0)
	{
		memset(arr,0,sizeof(arr));
		memset(tot,0,sizeof(tot));
		arr[0] = 1;
		int maxi = 1;
		for(int a=2;a<=n;a++)
		{
			long long mul = a;
			long long rem = 0;
			for(int b=0;b<maxi;b++)
			{
				arr[b] = arr[b] * mul + rem;
				rem = arr[b] / INF;
				arr[b] %= INF;
			}
			if(rem != 0) arr[maxi++] = rem;
		}
		for(int a=0;a<maxi;a++)
		{
			int to = 0;
			while(arr[a] != 0)
			{
				to++;
				tot[arr[a]%10]++;
				arr[a]/=10;
			}
			while(a != maxi - 1 && to < 9)
			{
				tot[0]++;
				to++;
			}
		}
		printf("%d! --\n",n);
		for(int a=0;a<10;a++)
		{
			printf("   (%d)%5d",a,tot[a]);
			if(a%5==4) printf("\n");
			else printf(" ");
		}
	}
}
