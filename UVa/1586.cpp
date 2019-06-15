#include<bits/stdc++.h>
using namespace std;

string in;

bool isdigit(char a)
{
	if(a>='0' && a<='9') return true;
	return false;
}

double value(char a)
{
	if(a=='C') return 12.01;
	if(a=='H') return 1.008;
	if(a=='O') return 16.00;
	return 14.01;
}

int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		cin>>in;
		int len = in.length();
		int tot = 0;
		double ans = 0;
		char c;
		for(int a=0;a<len;a++)
		{
			if(a!=0 && !isdigit(in[a]))
			{
				if(tot == 0) tot = 1;
				ans += value(c) * tot;
				tot = 0;
				c = in[a];
			}
			else if(!isdigit(in[a])) c = in[a];
			else tot = tot*10 + (in[a] - '0');
		}
		if(tot == 0) tot = 1;
		ans += value(c) * tot;
		printf("%.3lf\n",ans);
	}
}
