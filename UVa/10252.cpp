#include<bits/stdc++.h>
using namespace std;

int tot[26],ktot[26];

string in;

int main()
{
	while(getline(cin,in))
	{
		memset(tot,0,sizeof(tot));
		memset(ktot,0,sizeof(ktot));
		if(cin.eof()) return 0;
		int len = in.length();
		for(int a=0;a<len;a++)
		{
			if(in[a]>='a' && in[a]<='z') tot[in[a]-'a']++;
		}
		getline(cin,in);
		len = in.length();
		for(int a=0;a<len;a++)
		{
			if(in[a]>='a' && in[a]<='z') ktot[in[a]-'a']++;
		}
		for(int a=0;a<26;a++)
			for(int b=0;b<min(tot[a],ktot[a]);b++)
				printf("%c",a+'a');
		printf("\n");
	}
}
