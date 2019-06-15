#include<bits/stdc++.h>
using namespace std;

char tot[10000];
int input[10];
int main()
{
	int k=1;
	while(scanf("%[^\n]",tot)!=EOF)
	{
		getchar();
		int len=strlen(tot);
		for(int a=1;a<10;a++)
		{
			input[a]=0;
		}
		printf("Case #%d:\n",k);
		for(int a=0;a<len;a++)
		{
			switch(tot[a])
			{
				case 'a':
				{
					input[1]++;
					input[2]++;
					input[4]++;
					break;
				}
				case 'b':
				{
					input[1]++;
					input[2]++;
					input[3]++;
					input[5]++;
					break;
				}
				case 'c':
				{
					input[3]++;
					input[2]++;
					input[6]++;
					break;
				}
				case 'd':
				{
					input[1]++;
					input[7]++;
					input[4]++;
					input[5]++;
					break;
				}
				case 'e':
				{
					input[5]++;
					input[2]++;
					input[4]++;
					input[6]++;
					input[8]++;
					break;
				}
				case 'f':
				{
					input[3]++;
					input[5]++;
					input[6]++;
					input[9]++;
					break;
				}
				case 'g':
				{
					input[7]++;
					input[4]++;
					input[8]++;
					break;
				}
				case 'h':
				{
					input[9]++;
					input[7]++;
					input[8]++;
					input[5]++;
					break;
				}
				case 'i':
				{
					input[8]++;
					input[9]++;
					input[6]++;
					break;
				}
			}
			for(int b=1;b<10;b++)
			{
				if(input[b]>9) input[b]-=10;
			}
		}
		for(int a=1;a<10;a++)
		{
			if(a%3==0) printf("%d\n",input[a]);
			else printf("%d ",input[a]);
		}
		k++;
		memset(tot,'\0',sizeof(tot));
	}
}
