#include<bits/stdc++.h>
using namespace std;

char temp[10005];
char input[10005];

int main()
{
	while(1)
	{
		scanf("%[^\n]",input); getchar();
		int len=strlen(input);
		int w=0;
		if(len==4 && strcmp(input,"DONE")==0) break;
		for(int a=0;a<len;a++)
		{
			char k=tolower(input[a]);
			if(k>='a' && k<='z')
			{
				temp[w]=k;
				w++;
			}
		}
		bool ans=true;
		for(int a=0;a<w;a++)
		{
			if(temp[a]!=temp[w-a-1]) ans=false;
		}
		if(ans) printf("You won't be eaten!\n");
		else printf("Uh oh..\n");
	}
}
