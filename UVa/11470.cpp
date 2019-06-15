#include<bits/stdc++.h>
using namespace std;

int arr[15][15];
int tot[15];

int main()
{
	int n;
	int k =0;
	while(1)
	{
		k++;
		scanf("%d",&n);
		if(n==0) break;
		for(int a=0;a<n;a++)
			for(int b=0;b<n;b++) scanf("%d",&arr[a][b]);
		memset(tot,0,sizeof(tot));
		for(int a=0;a<(n+1)/2;a++)
		{
			for(int b=0+a;b<n-a;b++)
				tot[a]+=(arr[a][b] + arr[n-1-a][b]);
			for(int b=0+a;b<n-a;b++)
				tot[a]+=(arr[b][a] + arr[b][n-1-a]);
			tot[a]-=arr[a][a]+arr[a][n-a-1]+arr[n-a-1][a] + arr[n-a-1][n-a-1];
			if(a==n-a-1) tot[a] = arr[a][a];
		}
		printf("Case %d:",k);
		for(int a=0;a<(n+1)/2;a++)
			printf(" %d",tot[a]);
		printf("\n");
	}
}
