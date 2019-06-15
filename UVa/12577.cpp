#include<bits/stdc++.h>
using namespace std;

char in[190];

int main()
{
	int test=0;
	scanf("%s",in); getchar();
	do
	{
		test++;
		if(in[0]=='H') printf("Case %d: Hajj-e-Akbar\n",test);
		else printf("Case %d: Hajj-e-Asghar\n",test);
		scanf("%s",in); getchar();
	}while(in[0]!='*');
}
