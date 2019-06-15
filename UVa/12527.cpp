#include<bits/stdc++.h>
using namespace std;

int ans[5005];

int main()
{
	for(int a=1;a<=5000;a++)
	{
		int k = a;
		int mark[15];
		memset(mark,0,sizeof(mark));
		while(k!=0)
		{
			mark[k%10]++;
			k/=10;
		}
		bool ada = true;
		for(int b=0;b<=9;b++) if(mark[b]>1) ada = false;
		ans[a] = ans[a-1];
		if(ada==true) ans[a]++;
	}
	int A,B;
	while(scanf("%d %d",&A,&B)!=EOF)
	{
		printf("%d\n",ans[B]-ans[A-1]);
	}
}
