#include<bits/stdc++.h>
using namespace std;

string in;

int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		int v1=0,v2=0;
		for(int a=0;a<4;a++)
		{
			cin>>in;
			for(int b=0;b<4;b++)
			{
				int num = in[b]-'0';
				if(b%2==0)
				{
					num*=2;
					v2 = v2 + num%10 + num/10;
				}
				else v1 = v1 + num%10 + num/10;
			}
		}
		if((v1+v2)%10==0) printf("Valid\n");
		else printf("Invalid\n");
	}
}
