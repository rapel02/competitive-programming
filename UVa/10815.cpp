#include<bits/stdc++.h>
using namespace std;

set<string> s;

char in[]="abcdefghijklmnopqrstuvwxyz";

bool charac(char w)
{
	for(int a=0;a<26;a++)
	{
		if(tolower(w)==in[a]) return true;
	}
	return false;
}

int main()
{
	string temp;
	char ch;
	int k = 0;
	while(scanf("%c",&ch)!=EOF)
	{
		if(charac(ch)==true)
		{
			temp+=tolower(ch);
			k++;
		}
		else
		{
			if(k!=0) s.insert(temp);
			k = 0;
			temp.clear();
		}
	}
	if(k!=0) s.insert(temp);
	for(set<string>::iterator it = s.begin();it!=s.end();it++)
		cout<<*it<<endl;
}
