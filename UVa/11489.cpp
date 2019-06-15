#include<bits/stdc++.h>
using namespace std;

char N[1005];

int modu[5];

int main()
{
	int tc;
	scanf("%d",&tc);
	for(int a=1;a<=tc;a++)
	{
		scanf("%s",N);
		memset(modu,0,sizeof(modu));
		int len =strlen(N);
		int tot = 0;
		for(int b=0;b<len;b++)
		{
			modu[(N[b]-'0')%3]++;
			tot+=(N[b]-'0');
		}
		printf("Case %d: ",a);
		if(modu[tot%3]==0)
		{
			printf("T\n");
		}
		else
		{
			int ans = 0;
			if(tot%3!=0)
				ans = 1 + modu[0];
			else ans = modu[0];
			printf("%c\n",(ans%2==0)?'T':'S');
		}
	}
}
