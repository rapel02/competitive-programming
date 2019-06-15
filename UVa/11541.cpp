#include<bits/stdc++.h>
using namespace std;

bool isnum(char c)
{
	if(c>='0' && c<='9') return true;
	return false;
}

int main()
{
	int ntc;
	cin>>ntc;
	for(int tc=1;tc<=ntc;tc++)
	{
		string in;
		cin>>in;
		int len = in.length();
		printf("Case %d: ",tc);
		int num = 0;
		char c;
		for(int a=0;a<len;a++)
		{
			if(a!=0 && !isnum(in[a]))
			{
				for(int b=0;b<num;b++) printf("%c",c);
				num = 0;
				c = in[a];
			}
			else if(!isnum(in[a]))
			{
				c = in[a];
				num = 0;
			}
			else
			{
				num = num*10 + (in[a]-'0');
			}
		}
		for(int b=0;b<num;b++) printf("%c",c);
		printf("\n");
	}
}
