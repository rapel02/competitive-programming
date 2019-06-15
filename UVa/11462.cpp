#include<bits/stdc++.h>
using namespace std;

int arr[150];

int main()
{
	int tc;
	while(1)
	{
		scanf("%d",&tc);
		if(tc==0) break;
		for(int a=0;a<tc;a++)
		{
			int w;
			scanf("%d",&w);
			arr[w]++;
		}
		bool first = true;
		for(int a=1;a<=100;a++)
		{
			while(arr[a]!=0)
			{
				if(first==false) printf(" ");
				printf("%d",a);
				first = false;
				arr[a]--;
			}
		}
		printf("\n");
	}
}
