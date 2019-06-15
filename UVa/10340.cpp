#include<bits/stdc++.h>
using namespace std;

char in[1000005],in2[1000005];

int main()
{
	while(scanf("%s %s",in,in2)!=EOF)
	{
		int len1 = strlen(in);
		int len2 = strlen(in2);
		int i = 0;
		for(int a=0;a<len2;a++)
		{
			if(i==len1) break;
			if(in[i]==in2[a]) i++;
		}
		if(i==len1) printf("Yes\n");
		else printf("No\n");
	}
}
