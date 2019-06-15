#include<bits/stdc++.h>
using namespace std;

int main()
{
	int test;
	int rr,cc,r,c;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d %d",&r,&c);
		r-=2;
		c-=2;
		rr=r/3;
		cc=c/3;
		if(r%3!=0) rr++;
		if(c%3!=0) cc++;
		printf("%d\n",rr*cc);
	}
}
