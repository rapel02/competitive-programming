#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int h,m;
		char temp;
		scanf("%d%c%d",&h,&temp,&m);
		int val=720;
		val-=h*60+m;
		if(val<720)val+=720;
		h=val/60;
		h%=12;
		m=val%60;
		if(h==0) h=12;
		printf("%02d:%02d\n",h,m);
	}
}
