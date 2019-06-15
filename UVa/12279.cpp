#include<bits/stdc++.h>
using namespace std;

int main()
{
	int test=0;
	int que,num;
	scanf("%d",&que);
	do
	{
		test++;
		int ans=0;
		for(int a=0;a<que;a++)
		{
			scanf("%d",&num);
			if(num>0) ans++;
			else ans--;
		}
		printf("Case %d: %d\n",test,ans);
		scanf("%d",&que);
	}while(que!=0);
}
