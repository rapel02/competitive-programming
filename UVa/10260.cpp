#include<bits/stdc++.h>
using namespace std;

char input[1006];

char conv(char a)
{
	if(a=='B' || a=='F' || a=='P' || a=='V') return '1';
	else if(a=='C' || a=='G' || a=='J' || a=='K'||a=='Q' || a=='S' || a=='X' || a=='Z') return '2';
	else if(a=='D' || a=='T' ) return '3';
	else if(a=='L') return '4';
	else if(a=='M' || a=='N') return '5';
	else if(a=='R') return '6';
	else return '7';
}

int main()
{
	while(scanf("%s",input)!=EOF)
	{
		getchar();
		int len=strlen(input);
		int k=0;
		char ans[1005]={'\0'};
		for(int a=0;a<len;a++)
		{
			input[a]=conv(input[a]);
			//printf("%c",input[a]);K
		}
		for(int a=0;a<len;a++)
		{
			if(a!=0)
			{
				if(input[a]!='7' && input[a-1]!=input[a])
					printf("%c",input[a]);
			}
			else if(input[a]!='7')
			{
				printf("%c",input[a]);
			}
		}
		printf("\n");
	}
}
