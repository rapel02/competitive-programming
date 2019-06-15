#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int r,c,rr,cc;
		scanf("%d %d",&r,&c);
		rr=r/2;
		if(r%2!=0) rr++;
		cc=c/2;
		if(c%2!=0) cc++;
		int ans=rr*cc;
		if(r==c) ans=rr*(cc+1)/2;
		printf("%d\n",ans);
	}
}
