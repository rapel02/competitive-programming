#include<bits/stdc++.h>
using namespace std;

string in[150];
int len[150];


int main()
{
	int n;
	while(cin>>n)
	{
		int maxi = 0;
		for(int a=0;a<n;a++) cin>>in[a];
		sort(in,in+n);
		for(int a=0;a<n;a++)
		{
			len[a] = in[a].length();
			maxi = max(maxi,len[a]);
		}
		int ans = 0;
		for(int a=n;a>=1;a--)
		{
			int r = n/a;
			if(n%a!=0) r++;
			int le = (maxi + 2)*(a-1) + maxi;
			if(le <= 60)
			{
				ans = r;
				break;
			}
		}
		for(int a=0;a<60;a++) printf("-");
		printf("\n");
		for(int a=0;a<ans;a++)
		{
			bool isf = true;
			for(int b=a;b<n;b+=ans)
			{
				if(!isf) printf("  ");
				isf = false;
				cout<<in[b];
				for(int c=len[b];c<maxi;c++) printf(" ");
			}
			printf("\n");
		}
	}
}
