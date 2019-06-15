#include<bits/stdc++.h>
using namespace std;


char in[15000];

int order(char a)
{
	if(a>='0' && a<='9') return a-'0';
	if(a>='A' && a<='Z') return a-'A' + 10;
	return 100;
}

char conv(int a)
{
	if(a<10) return '0' + a;
	return 'A' + a-10;
}

int main()
{
	int fr,to;
	while(scanf("%d %d %s",&fr,&to,in)!=EOF)
	{
		bool ada = true;
		int len = strlen(in);
		for(int a=0;a<len;a++)
		{
			if(order(in[a]) >= fr) ada = false;
		}
		if(ada==false)
		{
			printf("%s is an illegal base %d number\n",in,fr);
		}
		else
		{
			printf("%s base %d = ",in,fr);
			long long temp = 0;
			for(int a=0;a<len;a++)
			{
				temp = temp * fr + order(in[a]);
			}
			stack<char>s;
			while(temp!=0)
			{
				s.push(conv(temp%to));
				temp/=to;
			}
			bool ada = false;
			while(!s.empty())
			{
				ada = true;
				printf("%c",s.top());
				s.pop();
			}
			if(ada==false) printf("0");
			printf(" base %d\n",to);
		}
	}
}
