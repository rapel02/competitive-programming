#include<bits/stdc++.h>
using namespace std;

int main()
{
	int tpo = -1;
	int tim = 0;
	int sp = 0;
	double add = 0;
	int hh,mm,ss;
	char c;
	while(scanf("%d:%d:%d%c",&hh,&mm,&ss,&c)!=EOF)
	{
		if(c == ' ')
		{
			tim = hh * 3600 + mm * 60 + ss;
			add += (sp * (tim - tpo) * 1.0) * 5.0 / 18000.0;
			tpo = tim;
			scanf("%d%c",&sp,&c);
		}
		else
		{
			tim = hh * 3600 + mm * 60 + ss;
			printf("%02d:%02d:%02d %.2lf km\n",hh,mm,ss,add + (sp * (tim - tpo) * 1.0) * 5.0 / 18000.0);
			add += (sp * (tim - tpo) * 1.0) * 5.0 / 18000.0;
			tpo = tim;
		}
	}
}
