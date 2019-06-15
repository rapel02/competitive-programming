#include<bits/stdc++.h>
using namespace std;

char in[1500];

int main()
{
	while(1)
	{
		scanf("%s",in); getchar();
		int len = strlen(in);
		if(len==1 && in[0]=='0') break;
		long long tot = 0;
		long long multi = 1;
		for(int a=len-1;a>=0;a--)
		{
			tot += multi*(in[a]-'0');
			multi*=2;
			multi++;
		}
		printf("%lld\n",tot);
	}
}
