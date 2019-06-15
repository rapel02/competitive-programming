#include<bits/stdc++.h>
using namespace std;

char in[1500000];
char ret[]="`1234567890-QWERTYUIOP[]ASDFGHJKL;ZXCVBNM,.";
char n[]="1234567890-=WERTYUIOP[]\\SDFGHJKL;'XCVBNM,./";

char conv(char w)
{
	for(int a=0;a<43;a++)
		if(n[a]==w) return ret[a];
}

int main()
{
	while(scanf("%[^\n]",in)!=EOF)
	{
		getchar();
		int len = strlen(in);
		for(int a=0;a<len;a++)
		{
			if(in[a]!=' ') printf("%c",conv(in[a]));
			else printf(" ");
		}
		printf("\n");
	}
}
