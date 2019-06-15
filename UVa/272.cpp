#include<bits/stdc++.h>
using namespace std;

char input[100005];

int main()
{
	bool ada=true;
	while(scanf("%[^\n]",input)!=EOF)
	{
		getchar();
		int len=strlen(input);
		for(int a=0;a<len;a++)
		{
			if(input[a]=='\"')
			{
				if(ada==true)
				{
					printf("``");
					ada=false;
				}
				else
				{
					printf("''");
					ada=true;
				}
			}
			else printf("%c",input[a]);
		}
		printf("\n");
	}
}
