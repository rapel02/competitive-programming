#include<bits/stdc++.h>
using namespace std;

char in[1500];

int main()
{
	while(1)
	{
		scanf("%s",in);
		if(in[0] =='0') break;
		int tot = 0;
		int len = strlen(in);
		for(int a=0;a<len;a++)
		{
			tot = tot *10 + in[a] - '0';
			tot%=17;
		}
		if(tot==0) printf("1\n");
		else printf("0\n");
	}
}
