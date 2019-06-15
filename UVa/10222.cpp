#include<bits/stdc++.h>
using namespace std;

char in[15000];

char res[]="`1234567890qwertyuiop[asdfghjklzxcvbnm, ";
char to[] ="234567890-=ertyuiop[]\\dfghjkl;'cvbnm,./ ";

char conv(char w)
{
	for(int a=0;a<40;a++)
		if(to[a]==w) return res[a];
}

int main()
{
	while(scanf("%[^\n]",in)!=EOF)
	{
		getchar();
		int len = strlen(in);
		for(int a=0;a<len;a++)
		{
			printf("%c",conv(tolower(in[a])));
		}
		printf("\n");
	}
}
