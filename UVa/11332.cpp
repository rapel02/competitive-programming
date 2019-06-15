#include<bits/stdc++.h>
using namespace std;

int main()
{
	int num;
	scanf("%d",&num);
	do
	{
		int ans=0;
		while(num!=0)
		{
			ans+=num%10;
			num/=10;
			if(num==0 && ans/10!=0)
			{
				num=ans;
				ans=0;
			}
		}
		printf("%d\n",ans);
		scanf("%d",&num);	
	}while(num!=0);
}
