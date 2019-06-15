#include<bits/stdc++.h>
using namespace std;

char in[10005];

int main()
{
	int test;
	scanf("%d",&test); getchar();
	while(test--)
	{
		scanf("%s",in); getchar();
		int mi=10000;
		int nc=10000;
		int f=10000;
		int len=strlen(in);
		if((len==1&&(in[0]=='1' && in[0]=='4')) || (len==2 && in[0]=='7'&& in[1]=='8')) printf("+\n");
		else
		{
			for(int a=0;a<len;a++)
			{
				if(in[len-2]=='3' && in[len-1]=='5')
				{
					printf("-\n");
					break;
				}
				else if(in[0]=='1' && in[1]=='9' && in[2]=='0')
				{
					printf("?\n");
					break;
				}
				else if(in[0]=='9' && in[len-1]=='4')
				{
					printf("*\n");
					break;
				}
			}
		}
	}
}
