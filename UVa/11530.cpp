#include<bits/stdc++.h>
using namespace std;

int main()
{
	char in[1005];
	int val[28]={1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,4,1,2,3,1,2,3,4,1};
	int test;
	scanf("%d",&test); getchar();
	for(int w=1;w<=test;w++)
	{
		scanf("%[^\n]",in);
		getchar();
		int len=strlen(in);
		int tot=0;
		for(int a=0;a<len;a++)
		{
			int num=in[a]-'a';
			if(num<0 || num >25) num=26;
			tot+=val[num];
		}
		printf("Case #%d: %d\n",w,tot);
	}
}
