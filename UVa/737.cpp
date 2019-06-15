#include<bits/stdc++.h>
using namespace std;


int main()
{
	int tc;
	while(1)
	{
		scanf("%d",&tc);
		if(tc<2||tc>1000) break;
		long long hix=-1e+15,lox=1e+15,hiy=-1e+15,loy=1e+15,hiz=-1e+15,loz=1e+15;
		bool aw=true;
		for(int a=0;a<tc;a++)
		{
			long long x,y,z,r;
			scanf("%lld %lld %lld %lld",&x,&y,&z,&r);
			if(a!=0 && (x>lox||x+r<hix||y>loy||y+r<hiy||z>loz||z+r<hiz))
			{
				aw= false;
			}
			lox = min(lox,x+r);
			loy = min(loy,y+r);
			loz = min(loz,z+r);
			hix = max(hix,x);
			hiy = max(hiy,y);
			hiz = max(hiz,z);
		}
		if(aw==true)
		{	
			if(lox<hix||loy<hiy||loz<hiz)
			{
				printf("0\n");
			}
			else
			{
			
			long long ans = abs(lox-hix)*abs(loy-hiy)*abs(loz-hiz);
			printf("%lld\n",ans);
			}
		}
		else printf("0\n");
	}
}
