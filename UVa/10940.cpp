#include<bits/stdc++.h>
using namespace std;


int main()
{
	int n;
	while(scanf("%d",&n)!=0)
	{
		if(n==0) break;
		int a=1;
		while(a<n)
		a=a*2;
		printf("%d\n",2*n-a);
	}
}
