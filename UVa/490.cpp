#include<bits/stdc++.h>
using namespace std;

char in[1500][1500];
int w[1500];

int main()
{
	int k = 0;
	int maxi = 0;
	while(gets(in[k])!=NULL)
	{
		w[k] = strlen(in[k]);
		maxi = max(maxi,w[k]);
		k++;
	}
	int c = 0;
	for(int a=0;a<maxi;a++)
	{
		for(int b=k-1;b>=c;b--)
		{
			if(in[b][a]!='\0') printf("%c",in[b][a]);
			else printf(" ");
		}
		printf("\n");
	}
}
