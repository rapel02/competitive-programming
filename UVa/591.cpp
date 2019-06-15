#include<bits/stdc++.h>
using namespace std;

int arr[1500];

int main()
{
	int k = 0;
	bool first = true;
	while(1)
	{
		k++;
		int n;
		scanf("%d",&n);
		if(n==0) break;
		int tot = 0;
		for(int a = 0;a<n;a++)
		{
			scanf("%d",&arr[a]);
			tot+=arr[a];
		}
		int ans = 0;
		for(int a=0;a<n;a++)
		{
			if(arr[a]<tot/n) ans += tot/n - arr[a];
		}
		printf("Set #%d\nThe minimum number of moves is %d.\n\n",k,ans);
	}
}
