#include<bits/stdc++.h>
using namespace std;

int mth[]={31,28,31,30,31,30,31,31,30,31,30,31};
char ans[8][20]={"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
int dt[15][35];


int main()
{
	int now=5;
	for(int a=0;a<sizeof(mth)/4;a++)
	{
		for(int b=1;b<=mth[a];b++)
		{
			dt[a+1][b]=now;
			now++;
			now%=7;
		}
	}
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int m,d;
		scanf("%d %d",&m,&d);
		printf("%s\n",ans[dt[m][d]]);
	}
}
