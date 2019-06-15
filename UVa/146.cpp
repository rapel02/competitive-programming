#include<bits/stdc++.h>
using namespace std;

char in[15000],temp[15000];

int main()
{
	while(1)
	{
		gets(in);
		int len = strlen(in);
		if(len==1 && in[0]=='#') break;
		strcpy(temp,in);
		next_permutation(temp,temp+len);
		if(strcmp(in,temp)>=0) printf("No Successor\n");
		else printf("%s\n",temp);
	}
}
