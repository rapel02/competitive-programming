#include<bits/stdc++.h>
using namespace std;

long long M[150000];
long long F[150000];


void compute()
{
	M[0] = 0;
	F[0] = 1;
	for(int a=1;a<150000;a++)
	{
		M[a] = M[a-1] + F[a-1];
		F[a] = M[a-1] + 1; 
	}
}

int main()
{
	compute();
	int n;
	while(1)
	{
		scanf("%d",&n);
		if(n==-1) break;
		printf("%lld %lld\n",M[n],F[n] + M[n]);
	}
}
