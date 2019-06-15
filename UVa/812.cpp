#include<bits/stdc++.h>
using namespace std;


vector<int> vec[55];
vector<int> ans;

bool mark[2005],mark2[55][2005];

int main()
{
	int n;
	int tc = 0;
	while(scanf("%d",&n),n)
	{
		if(tc!=0) printf("\n");
		tc++;
		int sum = 0;
		for(int a=0;a<n;a++)
		{
			int k;
			scanf("%d",&k);
			int maxi = 0;
			int temp = 0;
			vec[a].push_back(0);
			for(int b=1;b<=k;b++)
			{
				int w;
				scanf("%d",&w);
				temp = temp + (10-w);
				if(temp == maxi) vec[a].push_back(b);
				if(temp > maxi) maxi = temp, vec[a].clear(),vec[a].push_back(b);
			}
			sum+=maxi;
		}
		memset(mark,false,sizeof(mark));
		mark[0] = true;
		for(int a=0;a<n;a++)
		{
			int sz = vec[a].size();
			memset(mark2,false,sizeof(mark2));
			for(int b=0;b<sz;b++)
			{
				for(int c=0;c<=2000;c++)
				{
					if(c + vec[a][b] > 2000) break;
					if(mark[c]==true) mark2[b][c + vec[a][b]] = true;
				}
			}
			for(int c=0;c<=2000;c++)
			{
				mark[c] = false;
				for(int b=0;b<sz;b++) mark[c] |= mark2[b][c];
			}
		}
		printf("Workyards %d\n",tc);
		printf("Maximum profit is %d.\n",sum);
		int k = 0;
		printf("Number of pruls to buy:");
		for(int a=0;a<=2000;a++)
		{
			if(mark[a]==true) 
			{
				printf(" %d",a);
				k++;
			}
			if(k==10) break;
		}
		printf("\n");
		for(int a=0;a<n;a++) vec[a].clear();
	}
}
