#include<bits/stdc++.h>
using namespace std;

bool isletter(char c)
{
	if(c >= 'a' && c<='z') return true;
	if(c >= 'A' && c<='Z') return true;
	return false;
}

char lower(char a)
{
	if(a>='A' && a<='Z') return a-'A' + 'a';
	return a;
}

int main()
{
	int tc;
	cin>>tc;getchar();
	int tot[30];
	while(tc--)
	{
		string in;
		getline(cin,in);
		memset(tot,0,sizeof(tot));
		int maxi = 0;
		int len = in.length();
		for(int a=0;a<len;a++)
		{
			if(isletter(in[a]) == true)
			{
				tot[lower(in[a])-'a']++;
				maxi = max(tot[lower(in[a])-'a'],maxi);
			}
		}
		for(int a=0;a<26;a++)
		{
			if(tot[a] == maxi)
			{
				printf("%c",a +'a');
			}
		}
		printf("\n");
	}
}
