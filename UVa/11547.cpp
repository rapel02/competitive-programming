#include<bits/stdc++.h>
using namespace std;

int main()
{
	int test;
	scanf("%d",&test);
	while(test--)
	{
		int num;
		scanf("%d",&num);
		int ans=(((num*63+7492)*5-498)%100)/10;
		if(ans<0) ans*=-1;
		printf("%d\n",ans);
	}
}
