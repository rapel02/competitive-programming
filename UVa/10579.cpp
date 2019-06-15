#include<bits/stdc++.h>
using namespace std;


int num[3][1500];

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		memset(num,0,sizeof(num));
		num[1][0] = 1;
		num[2][0] = 1;
		int maxi = 1;
		for(int a=3;a<=n;a++)
		{
			int idx = a%3;
			int p1 = (a + 1)%3;
			int p2 = (a + 2)%3;
			int rem = 0;
			for(int b=0;b<maxi;b++)
			{
				num[idx][b] = num[p1][b] + num[p2][b] + rem;
				rem = num[idx][b]/10;
				num[idx][b]%=10;
			}
			if(maxi < 1000 && rem !=0) 
			{
				num[idx][maxi] = rem;
				maxi++;
			}
		}
		bool isz = true;
		int ct = 0;
		for(int a=maxi-1;a>=0;a--)
		{
			//if(isz==true && num[n%3][a] == 0) continue;
			isz = false;
			ct++;
			printf("%d",num[n%3][a]);
		}
		if(ct == 0) printf("0");
		printf("\n");
	}
}
