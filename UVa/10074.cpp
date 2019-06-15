#include<bits/stdc++.h>
using namespace std;

long long pref[150][150];

int main()
{
	int R,C;
	while(scanf("%d %d",&R,&C)!=EOF)
	{
		if(R+C==0) break;
		for(int a=1;a<=R;a++)
		{
			for(int b=1;b<=C;b++)
			{
				int temp;
				scanf("%d",&temp);
				pref[a][b] = pref[a][b-1] + (1^temp);
			}
		}
		int maxi = 0;
		for(int a=1;a<=C;a++)
		{
			for(int b=a;b<=C;b++)
			{
				int temp = 0;
				for(int c=1;c<=R;c++)
				{
					if(pref[c][b] -pref[c][a-1] != b - a + 1) temp = 0;
					else temp += b - a + 1;
					maxi = max(maxi,temp);
				}
			}
		}
		printf("%d\n",maxi);
	}
}
