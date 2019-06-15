#include<bits/stdc++.h>
using namespace std;

int main()
{
	int test;
	scanf("%d",&test);
	for(int a=1;a<=test;a++)
	{
		int l,w,h;
		scanf("%d %d %d",&l,&w,&h);
		if(l<=20 && w<=20 && h<=20) printf("Case %d: good\n",a);
		else printf("Case %d: bad\n",a);
	}
}
