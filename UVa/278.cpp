#include<bits/stdc++.h>
using namespace std;

int main()
{
	int test;
	scanf("%d",&test); getchar();
	while(test--)
	{
		char t,temp;
		int r,c;
		scanf("%c%c%d %d",&t,&temp,&r,&c); getchar();
		if(t=='r') printf("%d\n",min(r,c));
		else if(t=='k') printf("%d\n",r*c/2);
		else if(t=='Q') printf("%d\n",min(r,c));
		else if(t=='K') printf("%d\n",((r+1)/2)*((c+1)/2));
	}
}
