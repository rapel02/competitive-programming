#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	printf("Lumberjacks:\n");
	while(n--)
	{
		int prev = 0;
		int now = 0;
		int rem = 0;
		bool ans = true;
		for(int a=0;a<10;a++)
		{
			scanf("%d",&now);
			if(a==1) rem = (now-prev<0)?-1:1;
			if(a>1)
			{
				if(rem * (now-prev)<0) ans = false;
			}
			prev = now;
		}
		printf("%srdered\n",(ans==true)?"O":"Uno");
	}
}
