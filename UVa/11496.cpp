#include<bits/stdc++.h>
using namespace std;

int num[10005];
int pos[10005];
int main()
{
	int test;
	scanf("%d",&test);
	while(test!=0)
	{
		int ans=0;
		bool up=false,udah=true,first;
		for(int a=0;a<test;a++)
		{
			scanf("%d",&num[a]);
			if(a!=0)
			{
				pos[a]=num[a]-num[a-1];
			}
			if(a==(test-1))
			{
				pos[0]=num[0]-num[a];
			}
		}
		for(int a=0;a<test;a++)
		{
			if(a==0)
			{
				if(pos[a]*pos[test-1]<0) ans++;
			}
			else if(pos[a]*pos[a-1]<0) ans++;
		}
		printf("%d\n",ans);
		scanf("%d",&test);
	
	}
}
