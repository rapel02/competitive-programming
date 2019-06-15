#include<bits/stdc++.h>
using namespace std;
int main()
{
	while(1)
	{
		int a,ans;
		scanf("%d",&a);
		if(a==0) break;
		if(a<101) ans=91;
		else ans=a-10;
		printf("f91(%d) = %d\n",a,ans);
	}
}
