#include<bits/stdc++.h>
using namespace std;

char bhs[10005];

int main()
{
	int qq=1;
	while(1)
	{
		scanf("%s",bhs);
		if(bhs[0]=='#')
		{
			break;
		}
		else
		{
			printf("Case %d: ",qq);
			if(strcmp(bhs,"HELLO")==0) printf("ENGLISH");
			else if(strcmp(bhs,"HOLA")==0) printf("SPANISH");
			else if(strcmp(bhs,"HALLO")==0) printf("GERMAN");
			else if(strcmp(bhs,"BONJOUR")==0) printf("FRENCH");
			else if(strcmp(bhs,"CIAO")==0) printf("ITALIAN");
			else if(strcmp(bhs,"ZDRAVSTVUJTE")==0) printf("RUSSIAN");
			else printf("UNKNOWN");
			printf("\n");
		}
		qq++;
	}
}
