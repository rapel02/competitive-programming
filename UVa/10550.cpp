#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a,b,c,d;
	int putar;
	scanf("%d %d %d %d",&a,&b,&c,&d);
	do
	{
		putar=720;
		putar=putar+(a-b+40)%40*9;
		putar+=360;
		putar=putar+(c-b+40)%40*9;
		putar=putar+(c-d+40)%40*9;
		printf("%d\n",putar);
		scanf("%d %d %d %d",&a,&b,&c,&d);
	}while(a!=0 || b!=0 || c!=0 || d!=0);
}
