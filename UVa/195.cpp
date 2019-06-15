#include<bits/stdc++.h>
using namespace std;

char in[1500];

bool cmp(char a,char b)
{
	if(tolower(a)<tolower(b)) return true;
	if(tolower(a)==tolower(b)) return a<b;
	return false;
}

int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		scanf("%s",in);
		int len = strlen(in);
		sort(in,in+len,cmp);
		do
		{
			for(int a=0;a<len;a++) printf("%c",in[a]);
			printf("\n");
		}while(next_permutation(in,in+len,cmp));
	}
}
