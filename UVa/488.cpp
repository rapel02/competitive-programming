#include<bits/stdc++.h>
using namespace std;

int main()
{
	int tc;
	scanf("%d",&tc);
	bool per = true;
	while(tc--)
	{
		if(per==false) printf("\n");
		per = false;
		int n,k;
		scanf("%d %d",&n,&k);
		bool first = true;
		for(int a=1;a<=k;a++)
		{
			if(first==false) printf("\n");
			first = false;
			for(int b=1;b<=n;b++)
			{
				for(int c=1;c<=b;c++) printf("%d",b);
				printf("\n");
			}
			for(int b=n-1;b>=1;b--)
			{
				for(int c=1;c<=b;c++) printf("%d",b);
				printf("\n");
			}
		}
	}
}
