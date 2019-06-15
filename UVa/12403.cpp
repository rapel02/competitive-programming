#include<bits/stdc++.h>
using namespace std;

char in[105];

int main()
{
	int test;
	scanf("%d",&test); getchar();
	int mun=0;
	int temp=0;
	while(test--)
	{
		scanf("%[^\n]",in); getchar();
		if(in[0]=='r')
		{
			printf("%d\n",mun);
		}
		else
		{
			temp=0;
			int len=strlen(in);
			for(int a=7;a<len;a++)
			{
				temp=temp*10+(in[a]-'0');
			}
			mun+=temp;
		}
	}
}
