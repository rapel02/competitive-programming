#include<bits/stdc++.h>
using namespace std;

string in;

int main()
{
	int tc;
	scanf("%d",&tc); getchar();
	while(tc--)
	{
		getline(cin,in);
		int len = in.length();
		if(len==1) printf("SIMPLE\n");
		else if(in[len-2] =='A' && in[len-1] =='B') printf("FULLY-GROWN\n");
		else if(in[0] == 'B' && in[len-1] =='A') printf("MUTAGENIC\n");
		else printf("MUTANT\n");
	}
}
