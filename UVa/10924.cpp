#include<bits/stdc++.h>
using namespace std;

char in[1500];
int num[2000];

void cprime()
{
	num[1] = 0;
	num[0] = 1;
	for(int a=2;a<=1500;a++)
	{
		if(num[a]==0)
		{
			for(int b=a*a;b<=1500;b+=a) num[b] = a; 
		}
	}
}

int conv(char a)
{
	if(a>='a' && a<='z') return a - 'a' + 1;
	else return a-'A' + 27; 
}

int main()
{
	cprime();
	while(scanf("%s",in)!=EOF)
	{
		int len = strlen(in);
		int tot = 0;
		for(int a=0;a<len;a++)
		{
			tot += conv(in[a]);
		}
		if(num[tot]==0) printf("It is a prime word.\n");
		else printf("It is not a prime word.\n");
	}
}
