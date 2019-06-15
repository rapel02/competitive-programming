#include<bits/stdc++.h>
using namespace std;

char in[1500];

bool isvowel(char a)
{
	char w = tolower(a);
	if(w=='a' || w=='e' || w=='u' || w=='i' || w=='o') return true;
	return false;
}

int main()
{
	while(scanf("%[abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ]",in)!=EOF)
	{
		char temp;
		scanf("%c",&temp);
		if(isvowel(in[0])) printf("%say%c",in,temp);
		else if(in[0]=='\0') printf("%c",temp);
		else
		{
			int len = strlen(in);
			for(int a=1;a<len;a++) printf("%c",in[a]);
			printf("%cay%c",in[0],temp);
		}
		in[0]='\0';
	}
}
