#include<bits/stdc++.h>
using namespace std;

int main()
{
	int tc;
	scanf("%d",&tc);
	for(int ntc = 1 ;ntc<=tc;ntc++)
	{
		long long a[3];
		scanf("%lld %lld %lld",&a[0],&a[1],&a[2]);
		sort(a,a+3);
		printf("Case %d: ",ntc);
		if(a[0] + a[1]<=a[2] ||a[0]<1) printf("Invalid\n");
		else if(a[0]==a[1] && a[1]==a[2]) printf("Equilateral\n");
		else if(a[0]==a[1] || a[0]==a[2] || a[1]==a[2]) printf("Isosceles\n");
		else printf("Scalene\n");
	}
}
