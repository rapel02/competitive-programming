#include<bits/stdc++.h>
using namespace std;

char in[1500];

int main()
{
	while(gets(in)!=NULL)
	{
		int len = strlen(in);
		if(in[0]=='0' && len==1) break;
		int tot = 0;
		int k = 1;
		for(int a=0;a<len;a++)
			tot = tot + in[a] -'0';
		while(tot>9)
		{
			int c = 0;
			while(tot!=0)
			{
				c+=tot%10;
				tot/=10;
			}
			tot = c;
			k++;
		}
		if(tot!=9) printf("%s is not a multiple of 9.\n",in);
		else printf("%s is a multiple of 9 and has 9-degree %d.\n",in,k);
	}
}
