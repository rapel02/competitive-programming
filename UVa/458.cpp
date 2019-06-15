#include<bits/stdc++.h>
using namespace std;

char in[15000];

int main()
{
	while(scanf("%[^\n]",in)!=EOF)
	{
		getchar();
		int len = strlen(in);
		for(int a=0;a<len;a++)
			printf("%c",in[a]-7);
		printf("\n");
	}
}
