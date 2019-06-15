#include<bits/stdc++.h>
using namespace std;

char in[15000];

int main()
{
	while(gets(in)!=NULL)
	{
		int len = strlen(in);
		int tot = 0;
		for(int a=0;a<len;a++)
		{
			if(in[a]>='0' &&in[a]<='9') tot+=in[a]-'0';
			else
			{
				if(in[a]=='!')
				{
					printf("\n");
					tot = 0;
					continue;
				}
				char w = in[a];
				if(in[a]=='b') w = ' ';
				for(int b=0;b<tot;b++) printf("%c",w);
				tot = 0;
			}
		}
		printf("\n");
	}
}
