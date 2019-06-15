#include<bits/stdc++.h>
using namespace std;

int main()
{
	float a,b,c,d;
	scanf("%f %f %f %f",&a,&b,&c,&d);
	do
	{
		bool suc=true;
		float pos=0;
		float bef=0;
		float climb=b;
		float fat=b*d/100;
		int day=0;
		while(suc==true && a>pos)
		{
			day++;
			bef=pos;
			pos=pos+climb;
			if(pos>a)
			break;
			pos=pos-c;
			climb-=fat;
			if(climb<0) climb=0;
			if(pos<0)
			{
				suc=false;
				break;
			}
		}
		if(suc==true) printf("success on day %d\n",day);
		else printf("failure on day %d\n",day);
		scanf("%f %f %f %f",&a,&b,&c,&d);
	}while(a!=0);
}
