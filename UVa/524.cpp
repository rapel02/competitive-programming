#include<bits/stdc++.h>
using namespace std;

int arr[20];
int pos[20];
bool mark[20];
int n;

bool cprime(int a)
{
	bool prime = true;
	for(int b=2;b<a;b++)
		if(a%b==0) prime = false;
	return prime;
}

void permutate(int sw)
{
	if(sw==n+1)
	{
		for(int a=1;a<=n;a++)
		{
			if(a!=1) printf(" ");
			printf("%d",pos[a]);
		}
		printf("\n");
	}
	else
	{
		for(int a=2;a<=n;a++)
		{
			if(mark[a]==false)
			{
				if(sw==n)
				{
					if(cprime(a+pos[sw-1]) && cprime(a+pos[1]))
					{
						mark[a] = true;
						pos[sw] = a;
						permutate(sw+1);
					}
				}
				else if(cprime(a+pos[sw-1]))
				{
					mark[a] = true;
					pos[sw] = a;
					permutate(sw+1);
				}
				mark[a] = false;
			}
		}
	}
}

int main()
{
	int k = 0;
	while(scanf("%d",&n)!=EOF)
	{
		memset(mark,false,sizeof(mark));
		k++;
		if(k!=1) printf("\n");
		for(int a=1;a<=n;a++) arr[a] = a;
		pos[1] = 1;
		mark[1] = true;
		printf("Case %d:\n",k);
		permutate(2);
	}
}
