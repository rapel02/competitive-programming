#include<bits/stdc++.h>
using namespace std;

string in;

char chg(char a)
{	
	if(a=='3') return 'E';
	if(a=='0') return 'O';
	if(a=='1') return 'I';
	if(a=='4') return 'A';
	if(a=='9') return 'P';
	if(a=='8') return 'B';
	if(a=='5') return 'S';
	if(a=='2') return 'Z';
	if(a=='7') return 'T';
	if(a=='6') return 'G';
	return a;
}

int main()
{
	int n;
	scanf("%d",&n);getchar();
	for(int a=1;a<=n;a++)
	{
		if(a!=1) printf("\n");
		while(getline(cin,in))
		{
			int len = in.length();
			if(len==0) break;
			for(int b=0;b<len;b++)
			{
				printf("%c",chg(in[b]));
			}
			printf("\n");
		}
	}
}
