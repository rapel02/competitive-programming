#include<bits/stdc++.h>
using namespace std;

char in[1500000];
stack<char> s;

int cback(char a)
{
	if(a>='0' && a<='9') return a-'0';
	return a - 'A' + 10;
}

char conv(int a)
{
	if(a>=0 && a<=9) return '0' + a;
	return 'A' + a - 10;
}

int main()
{
	while(1)
	{
		scanf("%s",in);
		if(in[0]=='-') break;
		int len = strlen(in);
		if(in[1]=='x')
		{
			long long ans = 0;
			for(int a=2;a<len;a++)
			{
				ans = ans * 16 + cback(in[a]);
				//cout<<in[a]<<" "<<cback(in[a])<<endl;
			}
			printf("%lld\n",ans);
		}
		else
		{
			long long temp = 0;
			for(int a=0;a<len;a++) temp = temp*10 + (in[a]-'0');
			while(temp!=0)
			{
				s.push(conv(temp%16));
				temp/=16;
			}
			if(s.empty()) s.push(conv(0));
			printf("0x");
			while(!s.empty())
			{
				printf("%c",s.top());
				s.pop();
			}
			printf("\n");
		}
	}
}
