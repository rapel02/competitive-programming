#include<bits/stdc++.h>
using namespace std;

int main()
{
	int test;
	scanf("%d",&test);
	for(int a=1;a<=test;a++)
	{
		float c,d;
		scanf("%f %f",&c,&d);
		float f=9*c/5+32;
		f+=d;
		f=f-32;
		f=f*5/9;
		printf("Case %d: %.2f\n",a,f);
	}
}
