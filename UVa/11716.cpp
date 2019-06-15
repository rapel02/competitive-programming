#include<bits/stdc++.h>
using namespace std;

string in;

int main()
{
	int tc;
	cin>>tc; getchar();
	while(tc--)
	{
		getline(cin,in);
		int len = in.length();
		int sq = -1;
		for(int a=1;a*a<=len;a++) if(a*a==len) sq = a;
		if(sq==-1) printf("INVALID\n");
		else
		{
			string ans="";
			for(int a=0;a<sq;a++)
			{
				for(int b=a;b<len;b+=sq) ans+=in[b];
			}
			cout<<ans<<endl;
		}
	}
}
