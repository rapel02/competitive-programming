#include<bits/stdc++.h>
using namespace std;

int ord[15000];

string in[15000];

int main()
{
	int tc;
	scanf("%d",&tc); getchar();
	bool ff = true;
	while(tc--)
	{
		if(!ff) printf("\n");
		ff = false;
		int n = 1;
		while(1)
		{
			char temp;
			scanf("%d%c",&ord[n++],&temp);
			if(temp=='\n') break;
		}
		for(int a=1;a<n;a++) 
		{
			cin>>in[ord[a]];
			getchar();
		}
		for(int a=1;a<n;a++) cout<<in[a]<<endl;
		getchar();
	}
}
