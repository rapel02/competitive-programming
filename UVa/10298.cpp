#include<bits/stdc++.h>
using namespace std;

char in[1500000];
int pos[1500000],len;
int maxi;

int main()
{
	while(1)
	{
		scanf("%s",in); getchar();
		if(in[0]=='.') break;
		int len = strlen(in);
		int ans = 1;
		for(int a=2;a<=len;a++)
		{
			if(len%a==0)
			{
				int rep = len/a;
				bool ada = true;
				for(int b = rep;b<len;b++)
				{
					if(in[b]!=in[b%rep])
					{
						ada = false;
						break;
					}
				}
				if(ada==true) ans = max(ans,a);
			}
		}
		printf("%d\n",ans);
	}
}
