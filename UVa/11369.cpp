#include<bits/stdc++.h>
using namespace std;

int arr[20005];

bool cmp(int a,int b)
{
	return a>b;
}

int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		int n;
		scanf("%d",&n);
		for(int a=0;a<n;a++) scanf("%d",&arr[a]);
		sort(arr,arr+n,cmp);
		int tot = 0;
		for(int a=0;a<n;a++)
		{
			if(a%3==2)tot+=arr[a];
		}
		printf("%d\n",tot);
	}
}
