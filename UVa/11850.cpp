#include<bits/stdc++.h>
using namespace std;

int pos[100000];

int main()
{
	int test;
	scanf("%d",&test);
	while(test!=0)
	{
		for(int a=0;a<test;a++)
			scanf("%d",&pos[a]);
		sort(pos,pos+test);
		bool fin=true;
		for(int a=1;a<test;a++)
		{
			if(pos[a]-pos[a-1]>200) fin=false;
		}
		if(1422-pos[test-1]>100) fin=false;
		if(fin==true) printf("POSSIBLE\n");
		else printf("IMPOSSIBLE\n");
		scanf("%d",&test);
	}	
}
