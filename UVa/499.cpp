#include<bits/stdc++.h>
using namespace std;

int tot[150];

char in[15000];
int main()
{
	while(scanf("%[^\n]",in)!=EOF)
	{
		getchar();
		memset(tot,0,sizeof(tot));
		int maxi = -1;
		int len = strlen(in);
		for(int a=0;a<len;a++)
		{
			if(in[a]>='A' && in[a]<='Z') tot[in[a]]++,maxi = max(maxi,tot[in[a]]);
			else if(in[a]>='a' && in[a]<='z') tot[in[a]]++,maxi = max(maxi,tot[in[a]]);
		}
		for(int a=40;a<=130;a++)
		{
			if(tot[a]==maxi) printf("%c",a);
		}
		printf(" %d\n",maxi);
	}
}
