#include<bits/stdc++.h>
using namespace std;
int aa[3];
int main()
{
	int test;
	scanf("%d",&test);
	for(int a=1;a<=test;a++)
	{
		scanf("%d %d %d",&aa[0],&aa[1],&aa[2]);
		sort(aa,aa+3);
		printf("Case %d: %d\n",a,aa[1]);
	}
}
