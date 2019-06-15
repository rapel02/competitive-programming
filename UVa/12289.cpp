#include<bits/stdc++.h>
using namespace std;

char in[6];

int main()
{
	int test;
	scanf("%d",&test); getchar();
	while(test--)
	{
		scanf("%s",in); getchar();
		int len=strlen(in);
		if(len==5) printf("3\n");
		else if((in[0]=='o' && in[1]=='n') ||(in[2]=='e' && in[1]=='n') ||(in[0]=='o' && in[2]=='e')  ) printf("1\n");
		else printf("2\n");
	}
}
