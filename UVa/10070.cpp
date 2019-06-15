#include<bits/stdc++.h>
using namespace std;

char inp[100000005];

int main()
{
	int ff=0;
	while((gets(inp)))
	{
		if(ff!=0) printf("\n");
		ff=1;
		//getchar();
		int len=strlen(inp);
		int gan=0,gen=0,tot=0;
		bool leap=false;
		bool hu=false;
		bool bu=false;
		bool ada=false;
		int num=(inp[len-4]-'0')*1000+(inp[len-3]-'0')*100+(inp[len-2]-'0')*10+(inp[len-1]-'0');
		//printf("%d\n",num);
		if((num%400==0) || ((num%4==0) && (num%100!=0))) leap=true;
		for(int a=0;a<len;a++)
		{
			int num=(inp[a]-'0');
			if(a%2==0) gen+=num;
			else gan+=num;
			tot+=num;
		}
		//printf("%d %d %d\n",tot,gen,gan);
		if(((abs(gan-gen)%11)==0 )&& (inp[len-1]=='5'||inp[len-1]=='0')) bu=true;
		if((tot%3==0) && (inp[len-1]=='5'||inp[len-1]=='0')) hu=true;
		if(leap ==true || hu==true) ada=true;
		if(leap==true)
		{
			printf("This is leap year.\n");
			if(hu==true) printf("This is huluculu festival year.\n");
			if(bu==true) printf("This is bulukulu festival year.\n");
		}
		else
		{	
			if(hu==true) printf("This is huluculu festival year.\n");
			else printf("This is an ordinary year.\n");
		}
	}
}
