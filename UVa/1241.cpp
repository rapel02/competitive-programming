#include<bits/stdc++.h>
using namespace std;

int arr[15][1050];

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(arr,0,sizeof(arr));
		int n,m;
		scanf("%d %d",&n,&m);
		int tot=1<<n;
		for(int a=1;a<=m;a++)
		{
			int p;
			scanf("%d",&p);
			arr[0][p]=1;
		}
		int ans=0;
		for(int a=0;a<n;a++)
		{
			for(int b=1;b<=tot/(1<<a);b+=2)
			{
				if(arr[a][b]==arr[a][b+1]&&arr[a][b]==1) arr[a+1][(b+1)/2]=1;
				else if(arr[a][b]!=arr[a][b+1]) arr[a+1][(b+1)/2]=0,ans++;
				else arr[a+1][(b+1)/2]=0;
				//printf("%d ",ans);
			}
		}
		printf("%d\n",ans);
	}
}
