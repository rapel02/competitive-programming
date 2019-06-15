#include<bits/stdc++.h>
using namespace std;

int main()
{
	string in;
	while(getline(cin,in))
	{
		int len = in.length();
		if(in[0] >='0' && in[0] <= '9')
		{
			int num = 0;
			for(int a=len-1;a>0;a-=2)
			{
				num = (in[a]-'0')*10 + in[a-1]-'0';
				if(num < 32)
				{
					num*=10;
					num += (in[a-2] -'0');
					a--;
				}
				printf("%c",num);
			}
		}
		else 
			for(int a=len-1;a>=0;a--)
			{
				int num = in[a];
				while(num!=0)
				{
					printf("%d",num%10);
					num/=10;
				}
			}
		printf("\n");
	}
}
