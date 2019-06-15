#include<bits/stdc++.h>
using namespace std;

string in;
long long pref[30][30];

int main()
{
	int tc;
	scanf("%d",&tc); getchar(); getchar();
	while(tc--)
	{
		int n = 0;
		int len;
		int lenn = 0;
		memset(pref,0,sizeof(pref));
		while(getline(cin,in))
		{
			len = in.length();
			if(len!=0) lenn = len;
			if(len==0) break;
			n++;
			for(int a=1;a<=len;a++) pref[n][a] += pref[n][a-1] + (in[a-1]-'0');
		}
		len = lenn;
		int maxi = 0;
		for(int i=1;i<=len;i++)
		{
			for(int j=i;j<=len;j++)
			{
				int temp = 0;
				for(int k=1;k<=n;k++)
				{
					if(pref[k][j]-pref[k][i-1]!=j-i+1) temp = 0 ;
					else temp += j-i+1;
					maxi = max(maxi,temp);
				}
			}
		}
		printf("%d\n",maxi);
		if(tc!=0) printf("\n");
	}
}
