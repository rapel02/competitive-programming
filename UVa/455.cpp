#include<bits/stdc++.h>
using namespace std;

char in[1500000];
int pos[1500000],len;
int maxi;

int main()
{
	int n;
	scanf("%d",&n);getchar();
	bool first = true;
	while(n--)
	{
		getchar();
		if(first==false) printf("\n");
		first = false;
		scanf("%s",in); getchar();
		if(in[0]=='.') break;
		int len = strlen(in);
		int ans = len;
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
				if(ada==true) ans = min(ans,rep);
			}
		}
		printf("%d\n",ans);
	}
}
