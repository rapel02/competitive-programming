#include<bits/stdc++.h>
using namespace std;

int main()
{
	int test;
	int x,y,xx,yy;
	scanf("%d",&test);
	do
	{
		scanf("%d %d",&x,&y);
		for(int a=0;a<test;a++)
		{
			scanf("%d %d",&xx,&yy);
			if(x==xx || y==yy) printf("divisa\n");
			else if(xx<x && yy>y) printf("NO\n");
			else if(xx>x && yy>y) printf("NE\n");
			else if(xx<x && yy<y) printf("SO\n");
			else printf("SE\n");
		}
		scanf("%d",&test);
	}while(test!=0);
}
