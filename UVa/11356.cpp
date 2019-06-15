#include<bits/stdc++.h>
using namespace std;

char nmth[15][20]={"January","February","March","April","May","June","July","August","September","October","November","December"};
int mth[2][13]={{0,31,28,31,30,31,30,31,31,30,31,30,31},{0,31,29,31,30,31,30,31,31,30,31,30,31}};

int main()
{
	int t;
	scanf("%d",&t);
	for(int a=1;a<=t;a++)
	{
		int y,m,d;
		char tmp,mt[20],tmp2;
		scanf("%d%c%[^-]%c%d",&y,&tmp,mt,&tmp2,&d); getchar();
		for(int b=0;b<sizeof(nmth)/4;b++)
		{
			if(strcmp(nmth[b],mt)==0) m=b+1;
		}
		int ii;
		int idx;
		scanf("%d",&ii);
		while(ii!=0)
		{
			ii--;
			if((y%4==0&&y%100!=0)||(y%400==0)) idx=1;
			else idx=0;
			d++;
			if(d>mth[idx][m]) d=1,m++;
			if(m>12) y++,m=1;
		}
		printf("Case %d: %d-%s-%02d\n",a,y,nmth[m-1],d);
	}
}
