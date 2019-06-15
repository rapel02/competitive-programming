#include<bits/stdc++.h>
using namespace std;

int arr[3800];

int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		memset(arr,0,sizeof(arr));
		int p,n;
		scanf("%d",&n);
		scanf("%d",&p);
		for(int a=0;a<p;a++)
		{
			int temp;
			scanf("%d",&temp);
			for(int b=temp;b<=n;b+=temp)
			{
				arr[b]++;
			}
		}
		int ans = 0;
		for(int a=1;a<=n;a++)
		{
			if(arr[a]>0 && (a%7!=6 && a%7!=0)) ans++;
		}
		printf("%d\n",ans);
	}
}
