#include<bits/stdc++.h>
using namespace std;

char in1[250],in2[250];
int tot[250];

int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		scanf("%s %s",in1,in2);
		memset(tot,0,sizeof(tot));
		int len1 = strlen(in1);
		int len2 = strlen(in2);
		for(int a=0;a<max(len1,len2);a++)
		{
			if(a<len1) tot[a] += in1[a]-'0';
			if(a<len2) tot[a] += in2[a] -'0';
			if(tot[a]>9) tot[a+1]++,tot[a]%=10;
		}
		bool first = true;
		for(int a=0;a<max(len1,len2)+1;a++)
		{
			if(first==true &&tot[a]==0) continue;
			first = false;
			if(a==max(len1,len2) && tot[max(len1,len2)]==0) ;
			else printf("%d",tot[a]);
		}
		printf("\n");
	}
}
