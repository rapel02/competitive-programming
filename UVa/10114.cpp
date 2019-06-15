#include<bits/stdc++.h>
using namespace std;

pair<int,float> p[1005];

int main()
{
	int mo,www;
	float pa,lo;
	float sisa,pay;
	scanf("%d %f %f %d",&mo,&pa,&lo,&www);
	//printf("%d %f %f %d\n",mo,pa,lo,www);
	do
	{
		sisa=lo+pa;
		pay=lo/mo;
		for(int a=0;a<www;a++)
		{
			scanf("%d %f",&p[a].first,&p[a].second);
		}
		sort(p,p+www);
		//printf("%f\n",p[0].second);
		int day=-1;
		int idx=0;
		int ans=0;
		while(day==-1)
		{
			if(p[idx+1].first==ans) idx++;
			sisa=sisa-sisa*p[idx].second;
			if(sisa>lo) day=ans;
			lo-=pay;
			ans++;
		}
		if(day>mo) day=mo;
		if(day==1) printf("1 month\n");
		else printf("%d months\n",day);
		scanf("%d %f %f %d",&mo,&pa,&lo,&www);	
	}while(mo>=0);
}
