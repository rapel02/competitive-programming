#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b)
{
	return (b==0)?a:gcd(b,a%b);
}

int arr[150000];

int main()
{
	int n;
	while(scanf("%d",&n),n)
	{
		int tot = 0;
		for(int a=0;a<n;a++) scanf("%d",&arr[a]);
		for(int a=0;a<n;a++) for(int b=a+1;b<n;b++) if(gcd(arr[a],arr[b])==1) tot++;
		if(tot==0) printf("No estimate for this data set.\n");
		else printf("%.6lf\n",sqrt(n*(n-1) *6.0 /2.0 / tot));
	}
}
