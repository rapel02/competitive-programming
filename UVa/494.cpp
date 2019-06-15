#include<bits/stdc++.h>
using namespace std;

char in[150000];

bool isalpha(char a)
{
	if(a>='a' && a<='z') return true;
	if(a>='A' && a<='Z') return true;
	return false;
}

int main()
{
	while(scanf("%[^\n]",in)!=EOF)
	{
		bool isword = false;
		getchar();
		int tot = 0;
		int len = strlen(in);
		for(int a=0;a<len;a++)
		{
			if(isword==false && isalpha(in[a])==true)
			{
			//	printf("%d\n",a);
				isword = true;
				tot++;
			}
			else if(isword==true&&isalpha(in[a])==false) isword = false;
		}
		printf("%d\n",tot);
	}
}
