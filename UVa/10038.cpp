#include<bits/stdc++.h>
using namespace std;

int numb[3005];
int diff[3005];
int main()
{
	int many;
	bool ans;
	while(scanf("%d",&many)!=EOF)
	{
		ans=true;
		memset(diff,0,sizeof(diff));
		for(int a=0;a<many;a++)
		{
			scanf("%d",&numb[a]);
			if(a!=0)
			{
				int w=abs(numb[a]-numb[a-1]);
				if(w>=many) ans=false;
				else diff[w]++;
				if(diff[w]>1) ans=false;

			}
		}
		if(ans) printf("Jolly\n");
		else printf("Not jolly\n");
	}
}
