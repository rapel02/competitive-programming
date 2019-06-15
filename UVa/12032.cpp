#include<bits/stdc++.h>
using namespace std;

int pole[100005];

int main()
{
	int test;
	scanf("%d",&test);
	for(int a=1;a<=test;a++)
	{
		int ans=0;
		int t;
		scanf("%d",&t);
		pole[0]=0;
		for(int b=1;b<=t;b++)
		{
			scanf("%d",&pole[b]);
			ans=max(ans,pole[b]-pole[b-1]);
		}
		int b=0;
		int temp=ans;
		for(b=1;b<=t;b++)
		{
			if((pole[b]-pole[b-1])==temp) temp--;
			else if((pole[b]-pole[b-1])>temp)
			{
				ans++;
				break;
			}
		}
		printf("Case %d: %d\n",a,ans);
	}
}
