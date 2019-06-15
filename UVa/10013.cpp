#include<bits/stdc++.h>
using namespace std;

int c[1000005],d[1000005],res[1000005];

int main()
{
	int tc;
	scanf("%d",&tc);
	bool first = true;
	while(tc--)
	{
		if(first==false) printf("\n");
		first = false;
		int n;
		scanf("%d",&n);
		for(int a=0;a<n;a++) scanf("%d %d",&c[a],&d[a]);
		int tmp = 0;
		for(int a=n-1;a>=0;a--)
		{
			res[a] = c[a] + d[a] + tmp;
			if(a!=0) tmp=res[a]/10,res[a]%=10;
		}
		for(int a=0;a<n;a++) printf("%d",res[a]);
		printf("\n");
	}
}
