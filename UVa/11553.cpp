#include<bits/stdc++.h>
using namespace std;

int num[15][15];
int n;

int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		scanf("%d",&n);
		int arr[15];
		for(int a=0;a<n;a++) arr[a] = a;
		for(int a=0;a<n;a++)
			for(int b=0;b<n;b++) scanf("%d",&num[a][b]);
		int ans = 1000000;
		do
		{
			int temp = 0;
			for(int a=0;a<n;a++) temp+=num[arr[a]][a];
			ans = min(temp,ans);
		}while(next_permutation(arr,arr+n));
		printf("%d\n",ans);
	}
}
