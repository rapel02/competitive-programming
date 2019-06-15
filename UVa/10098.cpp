#include<bits/stdc++.h>
using namespace std;

char in[150];

int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		scanf("%s",in);
		int len = strlen(in);
		sort(in,in+len);
		do
		{
			for(int a=0;a<len;a++) printf("%c",in[a]);
			printf("\n");
		}while(next_permutation(in,in+len));
		printf("\n");
	}
}
