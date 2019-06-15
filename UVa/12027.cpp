#include<bits/stdc++.h>
using namespace std;

char in[10005];

int main()
{
	while(1)
	{
		scanf("%s",in); getchar();
		int len=strlen(in);
		if(len==1 && in[0]=='0') break;
		int zero = (len-1)/2;
		int num=(in[0]-'0');
		if(zero*2+1!=len) num=num*10+ (in[1]-'0');
		int now=1;
		while(now*now<=num)
		{
			now++;
		}
		printf("%d",now-1);
		for(int a=0;a<zero;a++) printf("0");
		printf("\n");
	}
}
