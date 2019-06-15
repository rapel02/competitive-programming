#include<bits/stdc++.h>
using namespace std;


char num[10][8]={
{'-','|','|',' ','|','|','-'},
{' ',' ','|',' ',' ','|',' '},
{'-',' ','|','-','|',' ','-'},
{'-',' ','|','-',' ','|','-'},
{' ','|','|','-',' ','|',' '},
{'-','|',' ','-',' ','|','-'},
{'-','|',' ','-','|','|','-'},
{'-',' ','|',' ',' ','|',' '},
{'-','|','|','-','|','|','-'},
{'-','|','|','-',' ','|','-'},
};

int main()
{
	int sizw;
	char input[10005];
	char temp;
	scanf("%d%c%s",&sizw,&temp,input);
	while(sizw!=0)
	{
		int len=strlen(input);
		int k=0;
		for(int a=0;a<=4;a++)
		{
			if(a==0||a==2 ||a ==4)
			{
				printf(" ");
				int w;
				if(a==0) w=0;
				else if(a==2) w=3;
				else if(a==4) w=6;
				for(int b=0;b<len;b++)
				{
					for(int c=0;c<sizw;c++)
					{
						printf("%c",num[input[b]-'0'][w]);
					}
					if(b!=len-1)printf("   ");
					else printf(" ");
				}
				printf("\n");
			}
			else
			{	
				int w=a;
				if(w!=1) w=a+1;
				for(int c=0;c<sizw;c++)
				{
					for(int b=0;b<len;b++)
					{	
						printf("%c",num[input[b]-'0'][w]);
						for(int d=0;d<sizw;d++)
						printf(" ");
						printf("%c",num[input[b]-'0'][w+1]);
						if(b!=len-1) printf(" ");
					}
					printf("\n");
				}
			}
		}
		printf("\n");
		scanf("%d%c%s",&sizw,&temp,input);
	}
}
