#include<bits/stdc++.h>
using namespace std;

int arr[150];
int arr2[150];

char in[150000];

void swaps(int b)
{
	for(int a=0;a<=b/2;a++) swap(arr[a],arr[b-a]);
}

int main()
{
	while(scanf("%[^\n]",in)!=EOF)
	{
		getchar();
		int n = 0;
		int len = strlen(in);
		bool sp = false;
		memset(arr,0,sizeof(arr));
		for(int a=0;a<len;a++)
		{
			if(in[a]!=' ') arr[n] = arr[n]*10 + (in[a]-'0'),sp = false;
			else if(sp==false) sp = true,n++; 
		}
		for(int a=0;a<=n;a++) arr2[a] = arr[a];
		sort(arr2,arr2+n+1);
		for(int a=0;a<=n;a++) 
		{
			if(a!=0) printf(" ");
			printf("%d",arr[a]);
		}
		printf("\n");
		for(int a=n;a>=0;a--)
		{
			int tp = arr2[a];
			if(arr2[a]==arr[a]) continue;
			for(int b=1;b<=n;b++)
			{
				if(arr[b]==arr2[a])
				{
					printf("%d ",n-b+1);
					swaps(b);
					break;
				}
			}
			printf("%d ",n-a+1);
			swaps(a);
		}
		printf("0\n");
	}
}
