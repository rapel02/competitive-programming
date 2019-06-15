#include<bits/stdc++.h>
using namespace std;

int main()
{
	int awal,akhir,a,b,ans,co,temp;
		bool sww=false;
	while(scanf("%d %d",&awal,&akhir)!=EOF)
	{
		ans=0;
		if(awal>akhir)
		{
			temp=awal;
			awal=akhir;
			akhir=temp;
			sww=true;
		}
		for(a=awal;a<=akhir;a++)
		{
			b=a;
			co=1;
			while(b!=1)
			{
				if(b%2==0)
				{
					b=b/2;
				}
				else b=b*3+1;
				co++;
			}
			if(co>ans) ans=co;
		}
		if(sww==true)
		{
			temp=awal;
			awal=akhir;
			akhir=temp;
			sww=false;
		}
		printf("%d %d %d\n",awal,akhir,ans);
	}
}
